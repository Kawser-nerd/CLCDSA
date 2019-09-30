# coding:utf-8

import sys
from collections import deque, defaultdict

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


n, m = LI()

G = [[] for _ in range(n)]
for _ in range(m):
    x, y = LI_()
    G[x].append(y)

# dp[????S]: S??????????????????
dp = [0] * (1 << n)
dp[0] = 1

for s in range(1 << n):
    for i in range(n):
        if s >> i & 1 == 0:
            continue

        # S - {v}
        others = s ^ (1 << i)

        for to in G[i]:
            # ???????v??S - {v}????????
            # -> ??v???????
            if others & (1 << to):
                break
        else:
            # v????????
            dp[s] += dp[others]

print(dp[-1])