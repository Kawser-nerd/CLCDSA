t = int(input())
abcd = [tuple(int(x) for x in input().split()) for _ in range(t)]

def calc_gcd(x, y):
    if x < y:
        x, y = y, x
    if y == 0:
        return x
    z = x % y
    return calc_gcd(y, z)

for a,b,c,d in abcd:
    if b > a or b > d:
        print('No')
        continue
    elif c >= b:
        print('Yes')
        continue
    g = calc_gcd(b, d)
    if b - g + (a % g) > c:
        print('No')
    else:
        print('Yes')