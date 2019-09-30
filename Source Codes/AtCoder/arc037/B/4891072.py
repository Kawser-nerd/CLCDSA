# -*- coding: utf-8 -*-
n,m = map(int,input().split())
uv = [[0,0] for _ in range(m)]
for i in range(m):
    uv[i][0],uv[i][1] = map(int,input().split())

ans = True
def dfs(num,back,arr):
    global ans
    if num in arr:
        ans = False
        return arr
    arr.append(num)
    for i in range(m):
        if uv[i][0] == num and uv[i][1] != back:
            dfs(uv[i][1],num,arr)
        if uv[i][1] == num and uv[i][0] != back:
            dfs(uv[i][0],num,arr)
    return arr

cand = []
cnt = 0
for i in range(1,n+1):
    if i not in cand:
        cand = dfs(i,0,cand)
        if ans == True:
            cnt += 1
        ans = True

print(cnt)