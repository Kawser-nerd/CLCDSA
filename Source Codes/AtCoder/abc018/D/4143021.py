from itertools import combinations

n, m, p, q, r = [int(x) for x in input().split()]

g = [[0 for _ in range(m)] for __ in range(n)]

for i in range(r):
    x, y, z = [int(x) for x in input().split()]
    g[x - 1][y - 1] = z


ans = 0
for xs in combinations(range(n), p):
    gs = [sum(g[x][y] for x in xs) for y in range(m)]
    gs.sort(reverse=True)
    ans = max(ans, sum(gs[:q]))

print(ans)