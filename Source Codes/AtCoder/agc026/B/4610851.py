t = int(input())
query = [tuple(map(int, input().split())) for _ in range(t)]
def gcd(x, y):
    if y == 0: return x
    return gcd(y, x % y)
for a, b, c, d in query:
    g = gcd(b, d)
    r = a % g
    m = ((c - r)//g + 1) * g
    if b <= m and b <= a and b <= d: print('Yes')
    else: print('No')