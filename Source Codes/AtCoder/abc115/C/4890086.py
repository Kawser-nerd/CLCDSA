N, K = map(int, input().split())
h = []
for _ in range(N):
    h.append(int(input()))

h.sort()

diff = []
for i in range(N - K + 1):
    diff.append(h[i + K - 1] - h[i])

print(min(diff))