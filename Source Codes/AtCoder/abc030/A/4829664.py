x = input()
takahashi = float(x.split(' ')[1]) / float(x.split(' ')[0])
aoki = float(x.split(' ')[3]) / float(x.split(' ')[2])

if takahashi == aoki:
    print('DRAW')
elif takahashi > aoki:
    print('TAKAHASHI')
else:
    print('AOKI')