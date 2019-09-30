#!usr/bin/env python3
from collections import defaultdict
from collections import deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS():return list(map(list, sys.stdin.readline().split()))
def S(): return list(sys.stdin.readline())[:-1]
def IR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = I()
    return l
def LIR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = LI()
    return l
def SR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = S()
    return l
def LSR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = SR()
    return l
mod = 1000000007

#A
def A():
    return

#B
def B():
    return

#C
def C():
    return

#D
def D():
    return

#E
def E():
    return

#F
def F():
    def bfs(s,g,n):
        bfs_map = [-1 for i in range(n)]
        bfs_map[s] = 0
        q = deque()
        q.append(s)
        fin = False
        while q:
            x = q.popleft()
            for y in range(n):
                if c[x][y] > 0 and bfs_map[y] < 0:
                    bfs_map[y] = bfs_map[x]+1
                    if y == g:
                        fin = True
                        break
                    q.append(y)
            if fin:
                break

        if bfs_map[g] == -1:
            return [None,0]
        path = [None for i in range(bfs_map[g]+1)]
        m = float("inf")
        path[bfs_map[g]] = g
        y = g
        for i in range(bfs_map[g])[::-1]:
            for x in range(n+1):
                if c[x][y] > 0 and bfs_map[x] == bfs_map[y]-1:
                    path[i] = x
                    if c[x][y] < m:
                        m = c[x][y]
                    y = x
                    break
        return [path,m]

    def ford_fulkerson(s,g,c,n):
        while 1:
            p,m = bfs(s,g,n)
            if not m:break
            for i in range(len(p)-1):
                c[p[i]][p[i+1]] -= m
                c[p[i+1]][p[i]] += m
        return sum(c[g])
    h,w = LI()
    a = SR(h)
    c = [[0 for i in range(h+w+2)] for j in range(h+w+2)]
    for y in range(h):
        for x in range(w):
            if a[y][x] == "S":
                c[0][y+1] = float("inf")
                c[0][h+x+1] = float("inf")
            if a[y][x] == "T":
                c[y+1][h+w+1] = float("inf")
                c[h+x+1][h+w+1] = float("inf")
            if a[y][x] == "o":
                c[y+1][h+x+1] = 1
                c[h+x+1][y+1] = 1
    ans = ford_fulkerson(0,h+w+1,c,h+w+2)
    if ans == float("inf"):
        print(-1)
    else:
        print(ans)
#G
def G():
    return

#H
def H():
    return

#Solve
if __name__ == "__main__":
    F()