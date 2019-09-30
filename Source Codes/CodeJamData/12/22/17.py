#!/usr/bin/env python3

from collections import deque
from heapq import *

T = int(input())

def is_valid(i, j):
    global N, M
    return 0 <= i < N and 0 <= j < M

def can_move(curi, curj, curh, desti, destj):
    global C, F
    if not is_valid(desti, destj):
        return False

    cC = C[curi][curj]
    cF = max(F[curi][curj], curh)
    dC = C[desti][destj]
    dF = max(F[desti][destj], curh)

    if dC - dF < 50:
        return False

    if dC - cF < 50:
        return False

    if cC - dF < 50:
        return False

    return True

def can_ever_move(curi, curj, desti, destj):
    return can_move(curi, curj, 0, desti, destj)

def time_till_can_move(curi, curj, curh, desti, destj):
    global C, F
    if can_move(curi, curj, curh, desti, destj):
        return 0

    cC = C[curi][curj]
    cF = F[curi][curj]
    dC = C[desti][destj]
    dF = F[desti][destj]

    ans = 0

    if curh-ans + 50 > dC:
        ans = max(ans, curh + 50 - dC)

    return ans

def calc_cost(curi, curj, curh):
    cF = F[curi][curj]
    return (10 if curh < cF+20 else 1)*10

dirs = [(0,1), (0,-1), (1,0), (-1,0)]

for case in range(1, T+1):
    H, N, M = map(int, input().split())
    C = [list(map(int, input().split())) for i in range(N)]
    F = [list(map(int, input().split())) for i in range(N)]
    #print("\n".join(" ".join(map(str, l)) for l in C))
    #print()
    #print("\n".join(" ".join(map(str, l)) for l in F))

    #format: (time, i, j)

    dQ = deque()
    dQ.append((0,0,0))
    visited = [[False]*M for i in range(N)]
    visited[0][0]=True
    Q = []
    while dQ:
        t = dQ.popleft()
        Q.append(t)
        for d in dirs:
            n = (0, t[1]+d[0], t[2]+d[1])
            if not can_move(t[1], t[2], H, n[1], n[2]):
                continue
            if visited[n[1]][n[2]]:
                continue
            visited[n[1]][n[2]] = True
            dQ.append(n)
    heapify(Q)

    visited = [[False]*M for i in range(N)]
    while Q:
        c = heappop(Q)
        if visited[c[1]][c[2]]:
            continue
        visited[c[1]][c[2]] = True

        if c[1] == N-1 and c[2] == M-1:
            ans = c[0]
            break;

        for d in dirs:
            n = [c[0], c[1]+d[0], c[2]+d[1]]
            if not can_ever_move(c[1], c[2], n[1], n[2]):
                continue
            if visited[n[1]][n[2]]:
                continue

            n[0] += time_till_can_move(c[1], c[2], H-c[0], n[1], n[2])
            n[0] += calc_cost(c[1], c[2], H-n[0])

            heappush(Q, tuple(n))

    print("Case #{}: {}".format(case, ans/10))
