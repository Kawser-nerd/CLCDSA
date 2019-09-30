N, M, P, Q, R = [int(x) for x in input().split()]
Z = [[] for x in range(N)]
for i in range(R):
    x, y, z = [int(x) for x in input().split()]
    Z[x-1].append((y - 1, z))

from itertools import combinations
ans = 0
for C in combinations(range(N), P):
    man = [0] * M
    for c in C:
        for z in Z[c]:
            man[z[0]] += z[1]
    man.sort(reverse=True)
    ans = max(ans, sum(man[:Q]))
print(ans)