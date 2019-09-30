import sys
from collections import deque, Counter
sys.setrecursionlimit(1000000)
N, K, L = map(int, input().split())
pq = [list(map(int, input().split())) for _ in range(K)]
rs = [list(map(int, input().split())) for _ in range(L)]

G_r = [[] for _ in range(N+1)]
for elem in pq:
    G_r[elem[0]].append(elem[1])
    G_r[elem[1]].append(elem[0])
G_t = [[] for _ in range(N+1)]
for elem in rs:
    G_t[elem[0]].append(elem[1])
    G_t[elem[1]].append(elem[0])


field_r = [None]*(N+1)


def dfs_r(i, idx):
    q = deque()
    q.append(i)
    field_r[i] = idx
    while q:
        tmp = q.pop()
        for pos in G_r[tmp]:
            if field_r[pos] is None:
                field_r[pos] = idx
                q.append(pos)
            else:
                continue
idx = 0
for i in range(1, N+1):
    if field_r[i] is None:
        dfs_r(i, idx)
        idx += 1


field_t = [None]*(N+1)


def dfs_t(i, idx):
    q = deque()
    q.append(i)
    field_t[i] = idx
    while q:
        tmp = q.pop()
        for pos in G_t[tmp]:
            if field_t[pos] is None:
                field_t[pos] = idx
                q.append(pos)
            else:
                continue
idx = 0
for i in range(1, N+1):
    if field_t[i] is None:
        dfs_t(i, idx)
        idx += 1

m = list(zip(field_r[1:], field_t[1:]))
cnt = Counter(m)
ans = []
for elem in list(m):
    ans.append(cnt[elem])
print(' '.join(map(str, ans)))