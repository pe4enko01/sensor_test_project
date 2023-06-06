#!/bin/sh

PROJECT_PATH=`dirs -l`
PROJECT_PATH=${PROJECT_PATH}/../..
WIDGETS_PATH=$PROJECT_PATH/src/GUI/widgets
LIBSWIDGETS_PATH=$WIDGETS_PATH/.libs
LIBSSWIDGETS_PATH=${PROJECT_PATH}/../setwidgets/plugins/libglade/.libs
LIBSUWIDGETS_PATH=${PROJECT_PATH}/../uniwidgets/plugins/libglade/.libs

LIBGLADE_MODULE_PATH="$LIBSWIDGETS_PATH"
test "`arch`" = "x86_64" && UNIWIDGETS_MODULE_PATH="/usr/lib64"
case $1 in
	-l|--local|local)
		shift
		LIBGLADE_MODULE_PATH="$LIBGLADE_MODULE_PATH:$LIBSSWIDGETS_PATH:$LIBSUWIDGETS_PATH"
		UNIWIDGETS_MODULE_PATH=${PROJECT_PATH}/../uniwidgets/plugins/uniset2/.libs
		;;
esac
export LIBGLADE_MODULE_PATH
export UNIWIDGETS_MODULE_PATH

START=uniset2-start.sh

${START} -f ./gui --pulsar-id pulsar --pulsar-msec 5000 --confile configure.xml --unideb-add-levels info,warn,crit,system