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

#include <kcmdlineargs.h>
#include <kaboutdata.h>

static const char description[] = I18N_NOOP( "Koopa" );

static const char version[] = "0.1";

static KCmdLineOptions options[] =
{
//    { "+[URL]", I18N_NOOP( "Document to open" ), 0 },
	KCmdLineLastOption
};

int main( int argc, char **argv )
{
	KAboutData about( "koopa", I18N_NOOP("Koopa"), version, description,
			  KAboutData::License_GPL, "(C) 2005 Fabrizio Montesi", 0, 0, "luxor@eos-software.it" );
	about.addAuthor( "Fabrizio Montesi", 0, "luxor@eos-software.it" );
	KCmdLineArgs::init( argc, argv, &about );
	KCmdLineArgs::addCmdLineOptions( options );

	KApplication app;
	Koopa *koopaWin = 0;

	if ( app.isRestored() ) {
		RESTORE( Koopa );
	} else {
		KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
		koopaWin = new Koopa;

		app.setMainWidget( koopaWin );
		koopaWin->show();
		args->clear();

		koopaWin->startThread( new KoopaInitThread );
	}

	return app.exec();
}

