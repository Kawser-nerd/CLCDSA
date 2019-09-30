def gcd(x, y):
    while y:
        x, y = y, x%y
    return x

A, B, C = map(int, input().split())

if  C % gcd(A, B) == 0 :
    print('YES')
else:
    print('NO')