N, x = map(int, input().split())
A = list(map(int, input().split()))
A += A
INF = 10 ** 18
ans = INF
B = [INF] * N
for cnt in range(N):
    for i in range(N):
        B[i] = min(B[i], A[N + i - cnt])
    ans = min(ans, cnt * x + sum(B))

print(ans)