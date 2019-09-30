#!/usr/bin/env python3
# vim:set ts=8 sw=4 et smarttab:
# Round 1C 2012

import sys
from fractions import Fraction
from math import sqrt

line = sys.stdin.readline()
fields = line.split()
assert len(fields) == 1
ntc = int(fields[0])

def solve(d, a, other_car):
    wait_time = Fraction(0)
    first = True
    for time, distance in other_car:
        if distance > d:
            if first:
                break
            time = last_time + (time - last_time) * (d - last_distance) / (distance - last_distance)
            distance = d
        first = False
        arrival_time = sqrt(2 * distance / a)
        if arrival_time < time:
            cur_wait_time = time - arrival_time
        else:
            cur_wait_time = Fraction(0)
        if cur_wait_time > wait_time:
            wait_time = cur_wait_time
        last_time, last_distance = time, distance
    arrival_time = sqrt(2 * d / a)
    return wait_time + arrival_time

for tc in range(1, ntc + 1):
    line = sys.stdin.readline()
    fields = line.split()
    assert len(fields) == 3
    d = Fraction(fields[0])
    n = int(fields[1])
    a = int(fields[2])
    other_car = []
    for _ in range(n):
        line = sys.stdin.readline()
        fields = line.split()
        assert len(fields) == 2
        time = Fraction(fields[0])
        distance = Fraction(fields[1])
        other_car.append((time, distance))
    line = sys.stdin.readline()
    fields = line.split()
    assert len(fields) == a
    print('Case #{0}:'.format(tc))
    for i in range(a):
        accel = Fraction(fields[i])
        ans = solve(d, accel, other_car)
        print(ans)
