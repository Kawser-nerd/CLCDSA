A, B, C, D = map(int, input().split())
if B / A > D / C:
    print('TAKAHASHI')
elif D / C > B / A:
    print('AOKI')
else:
    print('DRAW')