H, W = map(int, input().split())
Ass = [input() for _ in range(H)]

redss = [['#']+['.']*(W-1) for _ in range(H)]
bluess = [['.']*(W-1)+['#'] for _ in range(H)]

for i in range(H):
    if i % 2:
        redss[i]= ['#']*(W-1)+['.']
    else:
        bluess[i] = ['.']+['#']*(W-1)

for i in range(H):
    for j in range(W):
        if Ass[i][j] == '#':
            redss[i][j] = '#'
            bluess[i][j] = '#'

print('\n'.join(map(''.join, redss)))
print()
print('\n'.join(map(''.join, bluess)))