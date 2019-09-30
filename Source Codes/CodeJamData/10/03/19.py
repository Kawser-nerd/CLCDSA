#!/usr/bin/python

from __future__ import division
from __future__ import print_function

import sys


def solve(R, k, N, groups):
    groups = list(groups)
    total = sum(groups)
    ## fast case: RC can take all groups in 1 ride
    if total < k:
        return total * R
    d = {}
    for i, g in enumerate(groups):
        current = g
        j = i
        while True:
            j = (j+1) % N
            nextg = groups[j]
            if (current + nextg > k) or (j==i):
                break
            current += nextg
        d[i] = current, j
    money = 0
    start = 0
    history = []
    moneyhistory = []
    for i in xrange(R):
        history.append(start)
        moneyhistory.append(money)
        dmoney, dstart = d[start]
        money += dmoney
        start = dstart
        if start in history:
            break
    else:
        ## fast case: no cycles        
        return money
    index = history.index(start) # num rides before cycle
    initmoney = moneyhistory[index]
    cyclemoney = money - initmoney
    cyclesize = len(history) - index
    numcycles = int((R - index) / cyclesize)
    money = initmoney + cyclemoney*numcycles
    for i in xrange(R - numcycles*cyclesize - index):
        dmoney, dstart = d[start]
        money += dmoney
        start = dstart
    return money


def main(filename):
    with open(filename, "r") as f:
        for case, line in enumerate(f):
            if not case:
                T = int(line.strip())
                continue
            if case > T:
                break
            R, k, N = (int(c) for c in line.split())
            line = next(f)
            groups = (int(c) for c in line.split())
            print("Case #{0}: {1}".format(case, solve(R, k, N, groups)))


if __name__ == "__main__":
    main(sys.argv[1])
    sys.exit(0)

