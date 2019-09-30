n = int(input())
a = list(map(int, input().split()))

ret = 0
mod = int(1e9) + 7


def inv(x):
    return pow(x, mod - 2, mod)


inv_memo = [inv(i) for i in range(1, n+1)]
cum = [0] * (n + 1)

for i in range(n):
    cum[i + 1] = (cum[i] + inv_memo[i]) % mod

for i in range(n):
    ret += (cum[n - i] + cum[i+1] - 1) * a[i]
    ret %= mod
for i in range(2, n + 1):
    ret *= i
    ret %= mod
print(ret)