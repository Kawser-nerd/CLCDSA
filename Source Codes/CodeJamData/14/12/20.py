#!/usr/bin/env python

from sys import stdin

import sys
sys.setrecursionlimit(100000)

tt = stdin.readline()

tt = eval(tt)

edge = []
visit = set()

def dfs(i):
    global edge
    global visit
    visit.add(i)
    sum0 = 0
    sum1 = 1
    be = []
    for h in edge[i]:
        if not h in visit:
            ret = dfs(h)
            sum0 += ret[1]
            sum1 += ret[1]
            be.append(ret[1] - ret[0])
    be = sorted(be)
    if len(be) == 0:
        return (0, 1)
    elif len(be) == 1:
        return (sum1 - 1, sum1)
    else:
        ll = len(be)
        return (sum0 - be[ll - 1] - be[ll - 2], sum1)

for cc in range(1, tt + 1):
    tmp = stdin.readline()
    n = eval(tmp)
    edge = []
    for i in range(0, n + 1):
        edge.append([])
    for i in range(1, n):
        tmp = stdin.readline()
        tmp = tmp.split()
        j = eval(tmp[0])
        k = eval(tmp[1])
        edge[j].append(k)
        edge[k].append(j)
    res = n
    for i in range(1, n + 1):
        visit = set()
        tmp = dfs(i)
        if tmp[0] < res:
            res = tmp[0]
    print "Case #%d: %d" % (cc, res)
