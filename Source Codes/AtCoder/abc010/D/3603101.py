#!/usr/bin/python3
# -*- coding: utf-8 -*-

#!/usr/bin/python3
# -*- coding: utf-8 -*-


"""
https://beta.atcoder.jp/contests/abc009/tasks/abc010_3
"""

import sys
import math
from inspect import currentframe
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])

def debug_print(*args):
    names = {id(v):k for k,v in currentframe().f_back.f_locals.items()}
    print(', '.join(names.get(id(arg),'???')+' = '+repr(arg) for arg in args), file=sys.stderr)

class Ford_Fulkerson:
    def __init__(self, N):
        self.used = [False] * (N + 1)
        self.G = [[0] * (N + 1) for i in range(N + 1)]
        self.N = N
 
    def add_edge(self, fr, to, cap):
        self.G[fr][to] = cap
        # self.G[to][fr] = cap
 
    def dfs(self, v, t, f):
        if v == t:
            return f
 
        self.used[v] = True
        for i in range(self.N + 1):
            if v == i:
                continue
            if (not self.used[i]) and self.G[v][i] > 0:
                d = self.dfs(i, t, min(f, self.G[v][i]))
                if d > 0:
                    self.G[v][i] -= d
                    self.G[i][v] += d
                    return d
        return 0
 
    def max_flow(self):
        flow = 0
        while True:
            self.used = [False] * (self.N + 1)
            f = self.dfs(0, self.N, 10 ** 9)
            if f == 0:
                break
            flow += f
 
        return flow
    
N, G, E = map(int, input().split())
girls = list(map(int, input().split()))
friends = [list(map(int, input().split())) for _ in range(E)]

# id N?Goal
max_flow = Ford_Fulkerson(N)

for friend in friends:
    max_flow.add_edge(friend[0], friend[1], 1)
    max_flow.add_edge(friend[1], friend[0], 1)

for girl in girls:
    max_flow.add_edge(girl, N, 1)


print(max_flow.max_flow())