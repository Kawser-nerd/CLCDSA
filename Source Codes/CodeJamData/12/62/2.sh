#!/bin/bash
file="$1"
./B2.cc.bin 0 < "$file" > "$file.out.0" &
./B2.cc.bin 1 < "$file" > "$file.out.1" &
./B2.cc.bin 2 < "$file" > "$file.out.2" &
./B2.cc.bin 3 < "$file" > "$file.out.3" &
./B2.cc.bin 4 < "$file" > "$file.out.4" &
