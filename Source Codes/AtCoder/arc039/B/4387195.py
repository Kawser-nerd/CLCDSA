import math
N, K = map(int, input().split())

mod = 10 ** 9 + 7

def combination(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def combinations_with_replacement(n, r):
    return combination(n + r - 1, r)

if N > K:
    ans = combinations_with_replacement(N, K) % mod
else:
    ans = combination(N, K % N) % mod

print(ans)