def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)


N, K = map(int, input().split())
A = list(map(int, input().split()))
G = A[0]
for a in A:
    G = gcd(a, G)
print('POSSIBLE' if K % G == 0 and K <= max(A) else 'IMPOSSIBLE')