import sys
sys.setrecursionlimit(10**6)
N = int(input())
*A, = map(int, input().split())
G = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

def calc(S):
    if not S:
        return 0
    S.sort(reverse=1)
    if S[0] > sum(S[1:]):
        return sum(S[1:])
    return sum(S)//2
ok = 1
def dfs(v, p):
    global ok
    c = A[v]
    S = []
    for w in G[v]:
        if w == p:
            continue
        S.append(dfs(w, v))
    if not S:
        return c
    d = calc(S)
    s = sum(S)
    k = s - c
    if not 0 <= k <= d:
        ok = 0
    return s - 2*k
import random
random.seed()
*r, = range(N)
random.shuffle(r)
d = {}
for i in range(2):
    dfs(r[i], -1)

if ok:
    print('YES')
else:
    print('NO')