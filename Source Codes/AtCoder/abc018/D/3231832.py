import sys
from itertools import combinations

N, M, P, Q, R = map(int, input().split())

happy = [[0]*M for _ in [0]*N]
for x, y, z in (map(int, l.split()) for l in sys.stdin):
    happy[x-1][y-1] = z

ans = 0
for girls in combinations(range(N), P):
    h = [0]*M
    for g in girls:
        for m in range(M):
            h[m] += happy[g][m]

    v = sum(sorted(h)[-Q:])
    if ans < v:
        ans = v

print(ans)