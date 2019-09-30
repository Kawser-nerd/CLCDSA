N, K = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a) * K
for k in range(1, K):
    s -= a[k - 1] * (K - k)
for i, k in enumerate(range(N, N - K, -1)):
    s -= a[k - 1] * (K - i - 1)
print(s)