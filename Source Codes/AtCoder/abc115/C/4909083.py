N, K = map(int, input().split())
h = [int(input())for _ in range(N)]
h.sort()
c = [0] * (N - K + 1)
for i in range(N - K + 1):
    c[i] = h[i + K - 1] - h[i]
print(min(c))