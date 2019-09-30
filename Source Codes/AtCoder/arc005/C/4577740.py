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
if __name__ == "__main__":
    h,w = LI()
    stage = [list(input()) for i in range(h)]
    for y in range(h):
        for x in range(w):
            if stage[y][x] == "s":
                s = [y,x]
            if stage[y][x] == "g":
                g = [y,x]
            stage[y][x] = 1 if stage[y][x] == "#" else 0
    bfs_map = [[3 for i in range(w)] for j in range(h)]
    bfs_map[s[0]][s[1]] = 0
    d = [[1,0],[-1,0],[0,1],[0,-1]]
    q = [[0,s]]
    while q:
        a,p = heappop(q)
        y,x = p
        for dy,dx in d:
            if 0 <= y+dy < h and 0 <= x+dx < w:
                if bfs_map[y+dy][x+dx] > bfs_map[y][x]+stage[y+dy][x+dx]:
                    bfs_map[y+dy][x+dx] = bfs_map[y][x]+stage[y+dy][x+dx]
                    heappush(q,[bfs_map[y+dy][x+dx],[y+dy,x+dx]])

    if bfs_map[g[0]][g[1]] <= 2:
        print("YES")
    else:
        print("NO")
#D
def D():
    return

#E
def E():
    return

#F
def F():
    return

#G
def G():
    return

#H
def H():
    return

#Solve