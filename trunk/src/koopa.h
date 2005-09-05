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


#ifndef _KOOPA_H_
#define _KOOPA_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <qthread.h>
#include <qstring.h>
#include <qvaluevector.h>
#include <qlabel.h>

#include <kapplication.h>
#include <klocale.h>
#include <kprogress.h>
#include <kmainwindow.h>

class KoopaEvent : public QCustomEvent
{
public:
	enum Type {
		First = 1000,
		InitMessage,
		InitEnd,
		Last
	};

	KoopaEvent( KoopaEvent::Type type ) : QCustomEvent( type ) {}
	static bool isKoopaEvent( QEvent& e );
};

class Koopa : public KMainWindow
{
	Q_OBJECT
	public:
		Koopa();
		void startThread( QThread* thread );
		static void postEvent( QEvent* e );
		bool event( QEvent* e );
	private:
		QValueVector< QThread* > m_threads;
		QFrame *m_mainFrame;
	
		void initGUI();
		void initLoginGUI();
		static Koopa* getKoopaInstance();
};

#endif // _KOOPA_H_
