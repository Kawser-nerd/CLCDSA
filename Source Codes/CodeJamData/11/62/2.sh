#!/bin/bash
if [ ! -f "$1" ] ; then exit ; fi
./B-split.cc.bin < "$1"
rm *.out
./B2b.cc.bin < 0.in > 0.out &
./B2b.cc.bin < 1.in > 1.out &
./B2b.cc.bin < 2.in > 2.out &
./B2b.cc.bin < 3.in > 3.out &
