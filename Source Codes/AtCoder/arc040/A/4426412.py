r,b = 0,0
n = int(input())
for _ in range(n):
    s = input()
    for c in s:
        if c == 'R':
            r += 1
        elif c == 'B':
            b += 1
if r == b:
    print('DRAW')
elif r > b:
    print('TAKAHASHI')
else:
    print('AOKI')