A, B, C, D = map(int, input().split())

x = B/A
y = D/C

if x > y:
    print('TAKAHASHI')
elif x < y:
    print('AOKI')
else:
    print('DRAW')