AC_PREREQ(2.69)

AC_INIT([gscie], [1.0.0], [SendBugsHere@example.com])

AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build/autotools])
AC_CONFIG_SRCDIR([gscie])
AC_CONFIG_HEADER([config.h])

##
# Checks for programs
##
AC_PROG_CC
AC_PROG_INSTALL

##
# Checks for libraries
##

# This defines the GOBJECT_CFLAGS and GOBJECT_LIBS variables which are useful
# in the Makefile.am files
PKG_CHECK_MODULES([GOBJECT], [gobject-2.0 >= 2.38])

##
# Checks for typedefs, structures, and compiler characteristics
##

# Adds the latest standard flag (e.g. std=gnu99) to the compiler flags
AC_PROG_CC_STDC

# Compiler flags (you might need to do some checks and set these conditionally)
gscie_CFLAGS="-Wall -fopenmp"

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# library-specific macros
AM_PROG_AR
LT_INIT

##
# Introspection
##
GOBJECT_INTROSPECTION_CHECK([1.38.0])

##
# Output
##

# Exposes the gscie_CFLAGS variable to the Makefile.am files.
AC_SUBST(gscie_CFLAGS)

# You should generally have one entry here for each Makefile.am
AC_CONFIG_FILES([Makefile gscie/Makefile])

AC_OUTPUT

