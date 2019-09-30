# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

n = int(input())
ab = [list(map(int, input().split())) for _ in range(n)]

imos = [0] * 1000002
for ai, bi in ab:
    imos[ai] += 1
    imos[bi + 1] -= 1

pop = [0] * 1000001
tmp = 0
for i, imosi in enumerate(imos):
    if i == 1000001: break
    tmp += imosi
    pop[i] = tmp

print(max(pop))