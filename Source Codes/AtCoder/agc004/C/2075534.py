H,W = map(int,input().split())
src = [input() for i in range(H)]

ans1 = [['#'] + ['.']*(W-1) for i in range(H)]
ans2 = [['.']*(W-1) + ['#'] for i in range(H)]

for i in range(1,H-1):
    for j in range(1,W-1):
        if i%2:
            ans1[i][j] = '#'
            ans2[i][j] = src[i][j]
        else:
            ans1[i][j] = src[i][j]
            ans2[i][j] = '#'

for row in ans1:
    print(''.join(row))
print('')
for row in ans2:
    print(''.join(row))