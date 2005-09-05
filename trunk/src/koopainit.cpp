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

#include <kstandarddirs.h>


void KoopaInitThread::run()
{
	//QString q( locateLocal( "appdata", "data.lst" ) );
	/*KoopaInitMessageEvent* event = new KoopaInitMessageEvent( i18n( q ), 50 );
	KApplication::postEvent( Koopa::getKoopaInstance(), event );*/
	/*usleep( 1000000 );
	Koopa::postEvent( new KoopaInitMessageEvent( QString::null, 25 ) );
	usleep( 1000000 );
	Koopa::postEvent( new KoopaInitMessageEvent( QString::null, 25 ) );
	usleep( 1000000 );
	Koopa::postEvent( new KoopaInitMessageEvent( QString::null, 25 ) );
	usleep( 1000000 );
	Koopa::postEvent( new KoopaInitMessageEvent( QString::null, 25 ) );*/
	Koopa::postEvent( new KoopaInitEndEvent );
}
