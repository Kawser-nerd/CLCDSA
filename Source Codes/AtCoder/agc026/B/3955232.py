T = int(input())
ABCD = [[int(_) for _ in input().split()] for _ in range(T)]


def gcd(x, y):
    if x < y:
        return gcd(y, x)
    elif x % y == 0:
        return y
    else:
        return gcd(y, x % y)


for a, b, c, d in ABCD:
    if a < b or d < b:
        print('No')
    else:
        g = gcd(b, d)
        x = g * (c // g) + (a % g)
        if x <= c:
            x += g
        if x >= b:
            print('Yes')
        else:
            print('No')

# https://www.youtube.com/watch?v=eB0eT-948Vw