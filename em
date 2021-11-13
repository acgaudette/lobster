#!/bin/sh

test -z $1 && exit 1
clear

pushd .
cd dev/emscripten
cp $(dirname $1)/shell.html .
ls .

PATH="$PATH:/usr/lib/emscripten/" make -j16
popd

./emrun $1
