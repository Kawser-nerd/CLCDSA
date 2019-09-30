#!/usr/bin/python3

# COPIED FROM http://python-algorithms.readthedocs.io/en/latest/_modules/python_algorithms/basic/union_find.html

from collections import defaultdict

class UF:
    def __init__(self, N):
        self._id = list(range(N))
        self._count = N
        self._rank = [0] * N
        self._N = N
        self._symbol_to_index = {}
        self._index_to_symbol = {}

    def find(self, p):
        # For integer items, try to preserve natural 0--N order if
        # possible, even if the successive calls to find are not in
        # that order
        if isinstance(p, int) and p < self._N and \
           p not in self._index_to_symbol:
            self._symbol_to_index[p] = p
            self._index_to_symbol[p] = p
        else:
            # Non-integer items (e.g. string)
            self._symbol_to_index.setdefault(p, len(self._symbol_to_index))
            self._index_to_symbol.setdefault(self._symbol_to_index[p], p)
        i = self._symbol_to_index[p]
        if i >= self._N:
            raise IndexError('You have been exceeding the UF capacity')

        id = self._id
        while i != id[i]:
            id[i] = id[id[i]]   # Path compression using halving.
            i = id[i]
        return i

    def count(self):
        return self._count

    def connected(self, p, q):
        return self.find(p) == self.find(q)

    def union(self, p, q):
        id = self._id
        rank = self._rank

        i = self.find(p)
        j = self.find(q)
        if i == j:
            return

        self._count -= 1
        if rank[i] < rank[j]:
            id[i] = j
        elif rank[i] > rank[j]:
            id[j] = i
        else:
            id[j] = i
            rank[i] += 1

    def get_components(self):
        """List of symbol components (as sets)"""
        d = defaultdict(set)
        for i, j in enumerate(self._id):
            d[self.find(self._index_to_symbol.get(j, j))].add(
                self._index_to_symbol.get(i, i)
            )
        return list(d.values())

# END OF COPIED CODE

import math

def d(x, y):
    return math.sqrt((x[0] - y[0])**2 + (x[1] - y[1])**2 + (x[2] - y[2])**2)

def run():
    n, s = tuple(int(x) for x in input().split())
    asteroids = []
    for i in range(n):
        asteroids.append(tuple(int(x) for x in input().split())[:3])
    dists = []
    for i in range(n):
        for j in range(i, n):
            dists.append((d(asteroids[i], asteroids[j]), i, j))
    dists.sort()
    components = UF(n)
    for d_, i, j in dists:
        components.union(i, j)
        if components.connected(0, 1):
            return d_


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d: %f" % (i+1, res))
