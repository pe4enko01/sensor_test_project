
########### install files ###############




#original Makefile.am contents follow:

#DOC_CFG_USER = Dox.cfg
#
#DIRS = html
#DOCFILES = ${DIRS}/*.{html,css,png,gif}
#########################################################################
#
#if HAVE_DOXYGEN
#all: user
#user: ${DOC_CFG_USER}
#	${DOXYGEN} $<
#
#depend :
#
#clean: clean-local
#
#clean-local:
#	${RM} ${DOCFILES} *~
#
#re: clean all
#endif
