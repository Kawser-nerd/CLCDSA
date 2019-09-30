# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]

net = [[False] * N for _ in range(N)]
for Ai, Bi in AB:
    net[Ai - 1][Bi - 1] = True
    net[Bi - 1][Ai - 1] = True


for p in range(N):
    net2 = [False] * N
    for q in filter(lambda x: net[p][x], range(N)):
        if q == p: continue # unreachable ?
        for r in filter(lambda x: net[q][x], range(N)):
            if r == p: continue
            if net[p][r]: continue
            # print("#", p + 1, r + 1)
            net2[r] = True
    print(sum(net2))