#!usr/bin/env python3
from collections import defaultdict
import math
import bisect
import random
def LI(): return list(map(int, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()
def IIR(n): return [II() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
mod = 1000000007

#A

#B

#C
"""
h,w = LI()
sy,sx = LI()
gy,gx = LI()
sy -= 1
sx -= 1
gy -= 1
gx -= 1
s = SR(h)
bfs_map = [[float("inf") for i in range(w)] for j in range(h)]
bfs_map[sy][sx] = 0
move_y = [1,-1,0,0]
move_x = [0,0,1,-1]
q = [[sy,sx]]
while q:
    y,x = q.pop(0)
    for i in range(4):
        y += move_y[i]
        x += move_x[i]
        if y >= 0 and y < h and x >= 0 and x < w:
            if bfs_map[y][x] == float("inf") and s[y][x] == ".":
                bfs_map[y][x] = min(bfs_map[y][x],bfs_map[y-move_y[i]][x-move_x[i]]+1)
                q.append([y,x])
        y -= move_y[i]
        x -= move_x[i]

print(bfs_map[gy][gx])
"""
#D
a,b = LS()
a = list(map(int, a))
b = list(map(int, b))
for i in range(len(b)-len(a)):
    a.insert(0,0)
n = len(b)
dp = [[[[0 for i in range(2)] for j in range(2)] for h in range(2)] for k in range(20)]
dp[0][0][0][0] = 1
for i in range(n):
    for j in range(2):
        for k in range(2):
            for h in range(2):
                x = 0 if j else a[i]
                y = 9 if k else b[i]
                for d in range(x,y+1):
                    dp[i+1][j or d > a[i]][k or d < b[i]][h or d == 4 or d == 9] += dp[i][j][k][h]

ans = 0
for j in range(2):
    for k in range(2):
        ans += dp[n][j][k][1]
print(ans)

#E

#F

#G

#H

#I

#J

#K

#L

#M

#N

#O

#P

#Q

#R

#S

#T