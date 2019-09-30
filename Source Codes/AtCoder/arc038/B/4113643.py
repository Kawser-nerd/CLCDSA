#!/usr/bin/env python3
H, W = map(int, input().split())
S = [input() for _ in range(H)]


def dfs(i, j):
    global dp
    if i < 0 or i > H - 1 or j < 0 or j > W - 1 or S[i][j] == '#':
        return True

    if dp[i][j] is not None:
        return dp[i][j]
    res = False
    if not dfs(i + 1, j) or not dfs(i + 1, j + 1) or not dfs(i, j + 1):
        res = True
    dp[i][j] = res
    return dp[i][j]


dp = [[None] * W for _ in range(H)]
print('First' if dfs(0, 0) else 'Second')