gaim_coresources = \
	account.c \
	accountopt.c \
	blist.c \
	buddyicon.c \
	cmds.c \
	connection.c \
	conversation.c \
	core.c \
	debug.c \
	eventloop.c \
	ft.c \
	imgstore.c \
	log.c \
	md5.c \
	network.c \
	notify.c \
	plugin.c \
	pluginpref.c \
	pounce.c \
	prefix.c \
	prefs.c \
	privacy.c \
	proxy.c \
	prpl.c \
	request.c \
	roomlist.c \
	server.c \
	sha.c \
	signals.c \
	status.c \
	stringref.c \
	sound.c \
	sslconn.c \
	util.c \
	value.c \
	xmlnode.c

gaim_coreheaders = \
	account.h \
	accountopt.h \
	away.h \
	blist.h \
	buddyicon.h \
	cmds.h \
	connection.h \
	conversation.h \
	core.h \
	debug.h \
	eventloop.h \
	ft.h \
	imgstore.h \
	log.h \
	md5.h \
	network.h \
	notify.h \
	plugin.h \
	pluginpref.h \
	pounce.h \
	prefix.h \
	prefs.h \
	privacy.h \
	proxy.h \
	prpl.h \
	request.h \
	roomlist.h \
	server.h \
	sha.h \
	signals.h \
	status.h \
	stringref.h \
	sound.h \
	sslconn.h \
	util.h \
	value.h \
	version.h \
	xmlnode.h

noinst_LTLIBRARIES = libgaim.la
noinst_HEADERS = $(gaim_coreheaders) \
	internal.h \
	gaim.h

# -Wno-shadows is called to avoid receiving a lot of output from glib sources
libgaim_la_SOURCES = $(gaim_coresources) \
	koopa.c
libgaim_la_CFLAGS = $(GLIB_CFLAGS)
libgaim_la_LIBS = $(GLIB_LIBS)

AM_CPPFLAGS = \
	-DSYSCONFDIR=\"$(sysconfdir)\"
