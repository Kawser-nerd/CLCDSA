# coding:utf-8

import sys
# from collections import Counter, defaultdict

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


n = II()
s = SI()

W = [0]
E = [0]
for c in s:
    W.append(W[-1] + (c == 'W'))
    E.append(E[-1] + (c == 'E'))

e_max = E[-1]
ans = INF
for i in range(1, n + 1):
    ans = min(ans, W[i - 1] + e_max - E[i])

print(ans)