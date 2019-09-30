N, K = map(int, input().split())
h = [int(input()) for _ in range(N)]
h.sort()
ans = 10 ** 9
for i in range(0, N - K + 1):
  ans = min(ans, h[i + K - 1] - h[i])
print(ans)