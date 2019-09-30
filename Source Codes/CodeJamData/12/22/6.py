#!/usr/bin/python
#B.py
#Author: James Damore
#Created on: May 05, 2012
#Time-stamp: <2012-05-05 13:53:01>
#cat Downloads/B-small-attempt0.in | ~/B.py > output.txt

import math, sys
import numpy as np
import Queue

def dbgln(a): sys.stderr.write(str(a) + "\n")
def read_ints(lines=None, fmt=int):
    if lines is None: return map(int, raw_input().split())
    return [map(fmt, raw_input().split()) for _ in range(lines)]

RATE = 10.0
MIN_DIST = 50
MIN_WATER = 20
FAST = 1
SLOW = 10

def read_input():
    H, N, M = read_ints()
    ceil = read_ints(lines=N)
    floor = read_ints(lines=N)
    min_time = [['' for _ in range(M)] for _ in range(N)]
    min_time[0][0] = 0
    PQ = Queue.PriorityQueue()
    PQ.put((0, [0, 0]))
    def get(array, index):
        return array[index[0]][index[1]]
    while not PQ.empty():
        time, spot = PQ.get()
        if spot == [N - 1, M - 1]:
            return time
        for x, y in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            new_spot = [spot[0] + x, spot[1] + y]
            if 0 <= new_spot[0] < N and 0 <= new_spot[1] < M:
                if get(ceil, new_spot) - get(floor, new_spot) < 50 or \
                   get(ceil, spot) - get(floor, new_spot) < 50 or \
                   get(ceil, new_spot) - get(floor, spot) < 50 or \
                   get(min_time, new_spot) < time:
                    new_time = ''
                else: #possible
                    earliest_time = max((H - (min(get(ceil, spot), get(ceil, new_spot)) - MIN_DIST)) / RATE, time)
                    if earliest_time <= 0:
                        new_time = 0
                    elif get(floor, spot) + MIN_WATER > H - earliest_time * RATE:
                        new_time = SLOW + earliest_time
                    else:
                        new_time = FAST + earliest_time
                    if new_time < get(min_time, new_spot):
                        min_time[new_spot[0]][new_spot[1]] = new_time
                        PQ.put((new_time, new_spot))
    return 'Error'


numCases=input()
for i in range(1, numCases+1):
    #read_input()
    #dbgln(i)
    output = read_input()
    print "Case #%d:" % i, output
