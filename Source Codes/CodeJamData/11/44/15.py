#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vi:ts=4 sw=4 et

from __future__ import division
from __future__ import print_function

from heapq import heappush, heappop
import sys


class Action(object):
    def __init__(self, planet, conquer, threathen):
        self.planet = planet
        self.conquer = conquer
        self.threathen = threathen

        self.conquered = sum(conquer)
        self.threathened = sum(
            threathen[i] if conquer[i]==0 else 0
            for i in range(len(threathen))
        )

    def __cmp__(self, other):
        if self.conquered != other.conquered:
            return self.conquered - other.conquered
        else:
            return other.threathened - self.threathened

    def __repr__(self):
        return '<planet {0}, c={1}, t={2}>'.format(
            self.planet, self.conquered, self.threathened
        )


def run_testcase():
    P, W = [int(x.strip()) for x in raw_input().strip().split()]
    m = [ [0]*P for i in range(P) ]
    visited = [0]*P

    for pair in raw_input().strip().split():
        i, j = [int(x.strip()) for x in pair.split(',')]
        m[i][j] = m[j][i] = 1

    HOME = 0
    ENEMY = 1

    # Inserting the home planet
    tmp_conquer = [1] + [0]*(P-1)
    tmp_threathen = [ 1 if m[HOME][i] else 0 for i in range(P) ]

    heap = [ Action(0, tmp_conquer, tmp_threathen) ]

    while True:
        a = heappop(heap)

        if visited[a.planet]:
            continue
        visited[a.planet] = 1

        if m[a.planet][ENEMY]:
            return a.conquered-1, a.threathened
        else:
            # Trying to attack planet i
            for i in range(P):
                if visited[i] == 0 and m[a.planet][i]:
                    tmp_conquer = a.conquer[:]
                    tmp_conquer[i] = 1
                    tmp_threathen = a.threathen[:]
                    # Threatening neighbors
                    for j in range(P):
                        if m[i][j]:
                            tmp_threathen[j] = 1
                    b = Action(i, tmp_conquer, tmp_threathen)
                    heappush(heap, b)

    return -1, -1


max_testcases = int(raw_input().strip())
for T in range(1, max_testcases+1):
    print("Case #{0}: {1} {2}".format(T, *run_testcase()))
