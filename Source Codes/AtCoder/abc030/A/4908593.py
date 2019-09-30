A , B , C , D = map(int, input().split())
if B * C > A * D :
    print('TAKAHASHI')
elif B * C < A * D :
    print('AOKI')
else:
    print('DRAW')