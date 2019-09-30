a, b, c, d = map(int, input().split())

if c * b == a * d:
    print('DRAW')
elif c * b > a * d:
    print('TAKAHASHI')
else:
    print('AOKI')