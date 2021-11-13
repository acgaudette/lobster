#!/bin/sh

test -z $1 && exit 1
clear

bin/lobster --cpp $1
ls dev/compiled_lobster/src/

INP=
echo cont? && read -r $INP

cd dev
cmake -DLOBSTER_TOCPP=ON -DCMAKE_BUILD_TYPE=Release . && make -j16

cd ..
ls bin/compiled*
