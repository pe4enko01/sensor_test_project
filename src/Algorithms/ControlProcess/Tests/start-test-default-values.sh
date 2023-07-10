#!/bin/sh
START=uniset2-start.sh
$START -f uniset2-testsuite-xmlplayer --log-show-tests --confile ../configure.xml --testfile test-control-process-default-values.xml --show-result-report --show-test-log $*

