from functools import reduce


def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


N, K = map(int, input().split())
A = list(map(int, input().split()))
g = reduce(gcd, A)
print("POSSIBLE" if K % g == 0 and K <= max(A) else "IMPOSSIBLE")