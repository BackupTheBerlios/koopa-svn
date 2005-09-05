/***************************************************************************
 *   Copyright (C) 2005 by Fabrizio Montesi   *
 *   luxor@eos-software.it   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "koopa.h"
#include "koopainit.h"

#include <qdesktopwidget.h>
#include <kapplication.h>
#include <qlayout.h>
#include <kpushbutton.h>
#include <khtmlview.h>
#include <kurl.h>
#include <khtml_part.h>
#include <ktextedit.h>
#include <kpassdlg.h>
#include <qcheckbox.h>

#define INIT_WINDOW_WIDTH 200
#define INIT_WINDOW_HEIGHT 150

#define MAIN_WINDOW_WIDTH 350
#define MAIN_WINDOW_HEIGHT 300

Koopa* Koopa::getKoopaInstance()
{
	return (Koopa*) kapp->mainWidget();
}

Koopa::Koopa()
	: KMainWindow( 0, "Koopa" )
{
	initGUI();
}

void Koopa::initGUI()
{
	int x, y;

	m_mainFrame = new QFrame( this, "mainFrame" );
	setCentralWidget( m_mainFrame );

	QBoxLayout *layout = new QVBoxLayout( m_mainFrame, 0, 0, "vBoxLayout" );

	QLabel* initLabel = new QLabel( i18n( "Starting Koopa" ), m_mainFrame, "initLabel" );
	initLabel->setAlignment( QLabel::AlignHCenter | QLabel::AlignVCenter );
	layout->add( initLabel );
	layout->add( new KProgress( 100, m_mainFrame, "initProgressBar" ) );
	
	QDesktopWidget *desktop = kapp->desktop();

	x = ( desktop->width() - INIT_WINDOW_WIDTH ) / 2;
	y = ( desktop->height() - INIT_WINDOW_HEIGHT ) / 2;
	setGeometry( x, y, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT );
}

void Koopa::startThread( QThread* thread )
{
	if ( thread ) {
		kapp->lock();
		
		m_threads.push_back( thread );
				
		kapp->unlock();
		
		thread->start();
	}
}

bool Koopa::event( QEvent *e )
{
	if ( KoopaEvent::isKoopaEvent( *e ) ) {
		KoopaEvent *ke = (KoopaEvent*) e;
		switch( e->type() ) {
			case KoopaEvent::InitMessage:
				KoopaInitMessageEvent *kime = (KoopaInitMessageEvent*) ke;
				if ( !kime->message().isNull() )
					( (QLabel*)child( "initLabel" ) )->setText( kime->message() );
	
				int progress = kime->progress();
				if ( progress == -1 )
					( (KProgress*)child( "initProgressBar" ) )->setProgress( 0 );
				else
					( (KProgress*)child( "initProgressBar" ) )->advance( progress );
				break;
			case KoopaEvent::InitEnd:
				initLoginGUI();
				break;
			default:
				break;
		}
		return true;
	}
	
	return KMainWindow::event( e );
}

void Koopa::initLoginGUI()
{
	hide();

	child( "initLabel" )->deleteLater();
	child( "initProgressBar" )->deleteLater();
	
	/* Widgets containers creation */
	QSplitter* splitter = new QSplitter( m_mainFrame );
		QFrame* listFrame = new QFrame( splitter, "listFrame" );
		QFrame* bodyFrame = new QFrame( splitter, "bodyFrame" );
			QFrame* underFrame = new QFrame( bodyFrame, "underFrame" );
				QFrame* pwdFrame = new QFrame( underFrame, "pwdFrame" );
				QFrame* loginFrame = new QFrame( underFrame, "loginFrame" );
	
	/* Data widgets creation */
	KListBox* listBox = new KListBox( listFrame, "listBox" );
	KPushButton* koopaConfigButton = new KPushButton( listFrame, "koopaConfigButton" );
	koopaConfigButton->setGuiItem( KStdGuiItem::configure() );
	KTextEdit* infoEdit = new KTextEdit( bodyFrame, "infoEdit" );
	QLabel* pwdLabel = new QLabel( "<b>Password:</b>", pwdFrame, "pwdLabel" );
	KPasswordEdit* pwdEdit = new KPasswordEdit( pwdFrame, "pwdEdit" );
	QCheckBox* rememberPwdCheckBox = new QCheckBox( i18n( "Remember password" ), loginFrame, "rememberPwdCheckBox" );
	QCheckBox* autoConnCheckBox = new QCheckBox( i18n( "Auto connect" ), loginFrame, "autoConnCheckBox" );
	KProgress* connProgress = new KProgress( 100, loginFrame, "connProgress" );
	KPushButton* loginButton = new KPushButton( "Login", loginFrame, "loginButton" );
	
	/* Layout widgets */
	QLayout* layout;
	layout = new QVBoxLayout( listFrame, 0, 2, "vBoxLayout" );
	layout->add( listBox );
	layout->add( koopaConfigButton );
	layout = new QVBoxLayout( bodyFrame, 0, 2, "vBoxLayout" );
	layout->add( infoEdit );
	layout->add( underFrame );
		layout = new QVBoxLayout( underFrame, 0, 2, "vBoxLayout" );
		layout->add( pwdFrame );
		layout->add( loginFrame );
			layout = new QHBoxLayout( pwdFrame, 0, 2, "hBoxLayout" );
			layout->add( pwdLabel );
			layout->add( pwdEdit );
			QGridLayout* grid = new QGridLayout( loginFrame, 3, 2, 0, 2, "gridLayout" );
				grid->addWidget( rememberPwdCheckBox, 0, 0 );
				grid->addWidget( autoConnCheckBox, 1, 0 );
				grid->addWidget( connProgress, 2, 0 );
				grid->addMultiCellWidget( loginButton, 0, 2, 1, 1 );
			/*KURL url = "http://www.kde.org";
			KHTMLPart *htmlPart = new KHTMLPart();
			htmlPart->openURL( url );
			KHTMLView* p = new KHTMLView( htmlPart, bodyFrame, "htmlView" );
			bodyFrame->layout()->add( p );*/

	m_mainFrame->layout()->add( splitter );

	int x, y;
	QDesktopWidget *desktop = kapp->desktop();
	x = ( desktop->width() - MAIN_WINDOW_WIDTH ) / 2;
	y = ( desktop->height() - MAIN_WINDOW_HEIGHT ) / 2;
	setGeometry( x, y, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT );
	
	show();
}

void Koopa::postEvent( QEvent* e )
{
	KApplication::postEvent( getKoopaInstance(), e );
}

bool KoopaEvent::isKoopaEvent( QEvent& e )
{
	KoopaEvent::Type type = (KoopaEvent::Type) e.type();
	return ( type > KoopaEvent::First && type < KoopaEvent::Last );
}

#include "koopa.moc"
