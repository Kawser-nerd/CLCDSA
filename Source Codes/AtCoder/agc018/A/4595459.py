def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)


N, K = map(int, input().split())
a = list(map(int, input().split()))

g = a[0]
for aa in a:
    g = gcd(g, aa)

d = (max(a) - K)
if d >= 0:
    if d % g == 0:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')
else:
    print('IMPOSSIBLE')