# -*- coding: utf-8 -*-
a = [0]*10
for i in range(10):
    a[i] = list(input())

def dfs(x,y,arr):
    arr[y][x] = "x"
    for i in range(-1,2):
        for j in range(-1,2):
            if i == j or i == -j:
                continue
            if 0 <= x + i < 10 and 0 <= y + j < 10:
                if arr[y+j][x+i] == "o":
                    dfs(x+i,y+j,arr)
    return arr

def land_num(arr):
    cnt = 0
    for i in range(10):
        for j in range(10):
            if arr[i][j] == "o":
                dfs(j,i,arr[:])
                cnt += 1
    return cnt

ans = False
b = [[0] * 10 for _ in range(10)]
for i in range(10):
    for j in range(10):
        for k in range(10):
            for l in range(10):
                b[k][l] = a[k][l]
        b[j][i] = "o"
        if land_num(b) == 1:
            ans = True
            break

if ans:
    print("YES")
else:
    print("NO")