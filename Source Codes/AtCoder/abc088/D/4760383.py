import itertools
import math
from collections import deque
from collections import defaultdict
from itertools import permutations
import heapq
INF = float("inf")

H,W = map(int,input().split())
grid = [list(input()) for i in range(H)]

dist = [[INF]*W for i in range(H)]
dist[0][0] = 0

dxy = [(0,1),(1,0),(0,-1),(-1,0)]

q = deque([(0,0)])

while q:
    x,y = q.popleft()
    for dx,dy in dxy:
        nx,ny = x+dx ,y+dy
        if nx < 0 or ny <0 or nx >=W or ny >= H:
            continue
        if grid[ny][nx] == "#":
            continue
        if dist[ny][nx] < INF:
            continue
        q.append((nx,ny))
        dist[ny][nx] = dist[y][x] + 1
ans = 0
for i in range(H):
    ans += grid[i].count(".")
if dist[H-1][W-1] == INF:
    print(-1)
else:
    print(ans-dist[H-1][W-1]-1)