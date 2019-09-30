# encoding: utf-8
import sys
import heapq

input = sys.stdin.readline
inf = 10 ** 18

N = int(input())
a, b = map(int, input().split())
M = int(input())
xy = [list(map(int, input().split())) for i in range(M)]

tab = [[] for i in range(N)]
for xi, yi in xy:
    tab[xi - 1].append(yi)
    tab[yi - 1].append(xi)

d = [(0 if i == a - 1 else inf) for i in range(N)]
prev = [False] * N
cnt = [0] * N

q = []
heapq.heappush(q, (0, a))
while len(q) > 0:
    cost, hi = heapq.heappop(q)
    if cost >= d[b - 1]: continue
    for hj in tab[hi - 1]:
        if hj == prev[hi - 1]: continue
        alt = d[hi - 1] + 1
        if alt < d[hj - 1]:
            d[hj - 1] = alt
            prev[hj - 1] = hi
            heapq.heappush(q, (alt, hj))
                            
# print("#", d[b - 1])

memo = [[None] * (d[b - 1] + 1) for i in range(N)]

def back(pos, turn):
    if pos == a: return 1
    if memo[pos - 1][turn] != None: return memo[pos - 1][turn]
    ret = 0
    for src in tab[pos - 1]:
        if d[src - 1] > turn - 1: continue
        ret += back(src, turn - 1)
    ret = ret % (10 ** 9 + 7)
    memo[pos - 1][turn] = ret
    return ret

print(back(b, d[b - 1]))