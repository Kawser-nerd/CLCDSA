import sys
N = int(input())
a = sorted((v, i, j) for i, l in enumerate(sys.stdin) for j, v in enumerate(map(int, l.split())))
costs, indexes, types = zip(*a[:N])
total = sum(costs)

if len(set(indexes)) == N and len(set(types)) == 2:
    ans = float("inf")
    for i in range(N-1, max(-1, N-3), -1):
        ans = min(ans, total - costs[i] + (a[N][0] if indexes[i] != a[N][1] else a[N+1][0]))
    print(ans)
else:
    print(total)