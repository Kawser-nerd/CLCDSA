def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)


N, X = map(int, input().split())
x = list(map(int, input().split()))
x = sorted(x)
x = list(map(lambda arg: abs(arg - X), x))

g = x[0]
for xx in x:
    g = gcd(g, xx)
print(g)