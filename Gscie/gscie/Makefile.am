# preamble
# - This is so we can call += freely on these variables.
NULL =
AM_CPPFLAGS =
AM_CFLAGS =
BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
DISTCLEANFILES =
lib_LTLIBRARIES =
bin_PROGRAMS =

# C Preprocessor flags - GOBJECT_CFLAGS was defined by PKG_CHECK_MODULES
AM_CPPFLAGS += \
  $(GOBJECT_CFLAGS) \
  $(NULL)

# CFlags - we defined Gscie_CFLAGS with AC_SUBST
AM_CFLAGS += \
  $(gscie_CFLAGS) \
  $(OPENMP_CFLAGS) \
  $(NULL)

# Define source C and header files. Note that a few variables have been defined
# for you such as `top_srcdir` and `srcdir` which are convenient to use.
source_h = \
  $(top_srcdir)/gscie/gscie.h \
  $(top_srcdir)/gscie/gscie-array.h \
  $(NULL)

source_c = \
  gscie.c \
  gscie-array.c \
  $(NULL)

# This is defines the actual library to build.
lib_LTLIBRARIES += libgscie-1.0.la

# There are now several libgscie_1_0_la_* variables you can define to control
# additional library objects to include, source files, linker objects, etc.
# There is also a similar variable, bin_PROGRAMS, you can define here to define
# any programs you want to build.
libgscie_1_0_la_LIBADD = $(GOBJECT_LIBS)
libgscie_1_0_la_SOURCES = $(source_c) $(source_h)

# Now define the GIR file to make. This is an XML file that shows how the
# introspection utilities interpreted your source code. You should read this file
# to make sure everything was interpreted as you expected.
-include $(INTROSPECTION_MAKEFILE)

# Make sure the name of your library matches the name you defined in
# lib_LTLIBRARIES. Capitalization can be important in these steps.
INTROSPECTION_GIRS = Gscie_1_0_gir
# These are flags to pass to g-ir-scanner and g-ir-compiler.
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir) --warn-all
INTROSPECTION_COMPILER_ARGS =

if HAVE_INTROSPECTION
introspection_sources = $(libgscie_1_0_la_SOURCES)

# This step is fairly well documented in the Gnome wiki here:
# https://wiki.gnome.org/Projects/GObjectIntrospection/AutotoolsIntegration
Gscie-1.0.gir: libgscie-1.0.la
Gscie_1_0_gir_INCLUDES = GObject-2.0
Gscie_1_0_gir_CFLAGS = $(AM_CPPFLAGS)
Gscie_1_0_gir_PACKAGES =
Gscie_1_0_gir_LIBS = libgscie-1.0.la
Gscie_1_0_gir_FILES = $(introspection_sources)
Gscie_1_0_gir_NAMESPACE = Gscie
INTROSPECTION_GIRS += Gscie-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif
