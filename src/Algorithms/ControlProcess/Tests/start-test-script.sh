#!/bin/sh
START=uniset2-start.sh
pushd ../../../Services/Administrator/
./create &
popd
sleep 1 
pushd ../../../SharedMemory/
./start_share.sh &
popd
sleep 2
pushd ../../../../Build/src/Algorithms/ControlProcess/
pwd
./start_fg.sh &
popd
sleep 1

$START  -f uniset2-testsuite-xmlplayer --log-show-tests --confile ../configure.xml --testfile test-control-process.xml --show-result-report --show-test-log $*
