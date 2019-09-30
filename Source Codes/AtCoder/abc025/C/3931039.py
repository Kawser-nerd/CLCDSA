#!/usr/bin/env python3
b = [list(map(int, input().split())) for _ in range(2)]
c = [list(map(int, input().split())) for _ in range(3)]
s = sum(sum(x) for x in b) + sum(sum(x) for x in c)
dp = {}


def calc(li):
    score = 0
    for i in range(2):
        for j in range(3):
            if li[3 * i + j] == li[3 * (i + 1) + j]:
                score += b[i][j]
    for i in range(3):
        for j in range(2):
            if li[3 * i + j] == li[3 * i + (j + 1)]:
                score += c[i][j]
    return score


def dfs(color, n=9):
    if str(color) in dp:
        return dp[str(color)]
    if n == 0:
        return calc(color)

    m = -s if n % 2 else s
    for i in range(9):
        if not color[i] is None:
            continue

        color[i] = n % 2
        res = dfs(color, n - 1)
        color[i] = None
        m = max(m, res) if n % 2 else min(m, res)

    dp[str(color)] = m
    return m


chokudai = dfs([None] * 9)
naoko = s - chokudai
print(chokudai)
print(naoko)