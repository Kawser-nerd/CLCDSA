def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x%y)

def oneone(i, l, M):
    if i < 3:
        return sum(pow(10, j*l, M) for j in range(i)) % M
    else:
        return (oneone(2, (i//2)*l, M) * oneone(i//2, l, M) + (i%2) * pow(10, (i-1)*l, M)) % M

A, B, M = map(int, input().split())

g = gcd(A, B)

x = oneone(A//g, g, M)
y = oneone(B, 1, M)

print(x * y % M)