# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = koopa.h koopainit.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(EXTRACTRC) `find . -name \*.ui -o -name \*.rc` > rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/koopa.pot

KDE_ICON = AUTO

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = koopa

# the application source, library search path, and link libraries
koopa_SOURCES = main.cpp koopa.cpp koopainit.cpp
koopa_LDFLAGS = $(KDE_RPATH) $(all_libraries)
koopa_LDADD = $(LIB_KHTML) $(LIB_KDEUI)

# this is where the desktop file will go 
shelldesktopdir   = $(kde_appsdir)/Utilities
shelldesktop_DATA = koopa.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/koopa
shellrc_DATA = koopaui.rc

