# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(1000000)

a = [[0] * 10 for _ in range(10)]
for i in range(10):
    a[i] = list(input())

def land_search(m):
    m_reached = [[0] * 10 for _ in range(10)]
    cnt = 0
    for i in range(10):
        for j in range(10):
            if m[j][i] == "o" and m_reached[j][i] == 0:
                cnt += 1
                search(i,j,m,m_reached)
    return cnt

def search(x, y, m, m_reached):
    if x < 0 or x >= 10 or y < 0 or y >= 10:
        return False
    if m[y][x] == "x":
        return False
    if m_reached[y][x] == 1:
        return False
    m_reached[y][x] = 1

    if search(x+1, y,m,m_reached):
        return True
    if search(x-1, y,m,m_reached):
        return True
    if search(x, y+1,m,m_reached):
        return True
    if search(x, y-1,m,m_reached):
        return True
    return False

ans = False

if land_search(a) == 1:
    ans = True

for i in range(10):
    for j in range(10):
        ac = a[:]
        if a[j][i] == "x":
            ac[j][i] = "o"
            if land_search(ac) == 1:
                ans = True
            ac[j][i] = "x"

if ans:
    print("YES")
else:
    print("NO")