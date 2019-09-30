# -*- coding: utf-8 -*-

n = int(input())
t = [0] * n
for i in range(n):
    t[i] = int(input())

ans = float("inf")
def dfs(i, one, two):
    global ans
    if i == n:
        ans = min(ans,max(one,two))
        return
    dfs(i + 1,one + t[i],two)
    dfs(i + 1,one, two + t[i])
    return

dfs(0,0,0)
print(ans)