A, B, C, D = map(int, input().split())
TWin = B / A
AWin = D / C

if TWin > AWin:
    print('TAKAHASHI')
elif TWin < AWin:
    print('AOKI')
else:
    print('DRAW')