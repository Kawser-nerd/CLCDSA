from itertools import combinations

N, M, P, Q, R = map(int, input().split())
items = [dict() for _ in range(N)]
for _ in range(R):
    x, y, z = map(int, input().split())
    items[x-1][y-1] = z
ans = 0
for com in combinations(range(1, N + 1), P):
    man = [0 for _ in range(M)]
    for c in com:
        for k, v in items[c-1].items():
            man[k] += v
    man.sort(reverse=True)
    ans = max(ans, sum(man[:Q]))
print(ans)