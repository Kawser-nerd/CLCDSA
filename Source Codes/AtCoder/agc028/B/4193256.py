from itertools import accumulate
N = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
prob = [0] + list(accumulate([pow(i, mod-2, mod) for i in range(2, N+1)]))
total = 1
for i in range(2, N+1):
    total = total * i % mod

ans = 0
for n, left, right in zip(a, range(N), range(N-1, -1, -1)):
    ans += total * n * (1 + prob[left] + prob[right]) % mod

print(ans % mod)