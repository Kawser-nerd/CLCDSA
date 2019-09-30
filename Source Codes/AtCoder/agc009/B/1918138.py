#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**6)

N = int(input())

children = [[] * N for i in range(N)]
for i in range(N)[1:]:
    a = int(input()) - 1
    children[a].append(i)

def dfs(n):
    if children[n] == []:
        return 0
    dp = [dfs(child) for child in children[n]]
    dp.sort(reverse=True)
    return max(dp[i] + (i + 1) for i in range(len(dp)))

print(dfs(0))