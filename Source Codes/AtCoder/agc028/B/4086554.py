from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7


def extended_euclid(a, b):
    x1, y1, m = 1, 0, a
    x2, y2, n = 0, 1, b
    while m % n != 0:
        q = m // n
        x1, y1, m, x2, y2, n = x2, y2, n, x1 - q * x2, y1 - q * y2, m - q * n

    return (x2, y2, n)

g1 = [1, 1]

for i in range(2, N+1):
    g1.append((g1[-1] * i) % mod)

a = [0]
for i in range(N):
    a.append(extended_euclid(i+1, mod)[0])

a = list(accumulate(a))
ans = 0
for i in range(N):
    tmp = (a[N-i]-a[1])+(a[i+1]-a[1])+1
    ans += tmp*g1[N] * A[i]
    ans %= mod
print(ans)