N = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))
r = {}
for i in range(N):
    r[p[i]] = i + 1

A = [30000 * i for i in range(1, N + 1)]
B = [30000 * (N - i) + r[i - 1] for i in range(1, N + 1)]
print(*A)
print(*B)