# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

N, M = map(int, input().split())
lrs = [list(map(int, input().split())) for _ in range(N)]

imos = [0] * (M + 1)
for li, ri, si in lrs:
    imos[li - 1] += si
    imos[ri] -= si

tmp = 0
loss = [0] * M
for i, imosi in enumerate(imos):
    if i == M: break
    tmp += imosi
    loss[i] = tmp

print(sum([si for li, ri, si in lrs]) - min(loss))