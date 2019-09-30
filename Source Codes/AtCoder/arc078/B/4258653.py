# -*- coding: utf-8 -*-

import sys


class UnionFind:
    '''
    ??????UnionFind
    '''

    def __init__(self, size):
        self.table = [i for i in range(size)]

    def find(self, x):
        '''
        x??????????
        '''
        return self.table[x]

    def union(self, val, y):
        '''
        Fennec?0
         Snuke?N-1???????O(1)???
         '''
        self.table[y] = val

    def same(self, x, y):
        '''
        x?y?????????true
        '''
        x1 = self.find(x)
        y1 = self.find(y)
        return x1 == y1

    def get_table(self):
        return self.table
# python template for atcoder1


sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
adj = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)

Un = UnionFind(N)
S = [N-1]
F = [0]
S_or = N-1
F_or = 0


def oneStep(turn):
    ret = []
    if turn == 1:
        while S:
            c = S.pop(0)
            for i in adj[c]:
                if not Un.same(S_or, i) and not Un.same(F_or, i):
                    Un.union(S_or, i)
                    ret.append(i)
    else:
        while F:
            c = F.pop(0)
            for i in adj[c]:
                if not Un.same(S_or, i) and not Un.same(F_or, i):
                    Un.union(F_or, i)
                    ret.append(i)
    return ret


turn = 0
while S or F:
    if turn == 1:
        if len(S) != 0:
            S = oneStep(turn)
        turn = 0
    else:
        if len(F) != 0:
            F = oneStep(turn)
        turn = 1

cntF = Un.get_table().count(0)
cntS = Un.get_table().count(N-1)
if cntF > cntS:
    ans = "Fennec"
else:
    ans = "Snuke"
print(ans)