import numpy as np

def dp(v, d, c):
    if memo[v-1][d]:
        return

    memo[v-1][d] = True
    if d == 0:
        res[v-1] = str(c)
        return

    dp(v, d-1, c)
    for e in dic[v-1]:
        dp(e, d-1, c)


N, M = [int(e) for e in input().split(' ')]

dic = [[] for _ in range(N)]
memo = [[False]*11 for _ in range(N)]

for m in range(M):
    a, b = [int(e) for e in input().split(' ')]
    dic[a-1].append(b)
    dic[b-1].append(a)

Q = int(input())


vdc = [[int(e) for e in input().split(' ')] for _ in range(Q)]

res = ['0']*N

[dp(v, d, c) for v, d, c in vdc[::-1]]


print('\n'.join(res))