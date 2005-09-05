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

#ifndef _KOOPA_INIT_H_
#define _KOOPA_INIT_H_

class KoopaInitThread : public QThread
{
public:
	void run();
};

class KoopaInitMessageEvent : public KoopaEvent
{
public:
	KoopaInitMessageEvent( QString message, int progress = -1 )
		: KoopaEvent( KoopaEvent::InitMessage ), m_message( message )
	{
		m_progress = progress;
	}
	inline QString message() const { return m_message; }
	inline int progress() const { return m_progress; }
private:
	QString m_message;
	int m_progress;
};

class KoopaInitEndEvent : public KoopaEvent
{
public:
	KoopaInitEndEvent() : KoopaEvent( KoopaEvent::InitEnd ) {}
};


#endif // _KOOPA_INIT_H_
