a = ''
for _ in range(int(input())):
    a += input()
rt = a.count('R')
ba = a.count('B')
if rt == ba:
    print('DRAW')
elif rt > ba:
    print('TAKAHASHI')
else:print('AOKI')