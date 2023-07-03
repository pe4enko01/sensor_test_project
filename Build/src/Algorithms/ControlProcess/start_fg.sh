#!/bin/sh

START=uniset2-start.sh

${START} -f ./controlprocess --ulog-add-levels info,warn,crit --dlog-add-levels info,warn,crit --ControlProcess-log-add-levels any

