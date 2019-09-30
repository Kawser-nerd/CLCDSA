N = int(input())
L = [input() for _ in range(N)]

tmp1 = 0
tmp2 = 0
for i in range(N):
    for j in range(N):
        if L[i][j] == 'R':
            tmp1 += 1
        if L[i][j] == 'B':
            tmp2 += 1
            
if tmp1 > tmp2:
    print('TAKAHASHI')
elif tmp1 < tmp2:
    print('AOKI')
else:
    print('DRAW')