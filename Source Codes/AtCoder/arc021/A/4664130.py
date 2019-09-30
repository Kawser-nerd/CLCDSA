a = []
f = False
for _ in range(4):
    a.append(list(map(int,input().split())))
for i in range(4):
    for j in range(3):
        if a[i][j] == a[i][j+1]:
            f = True
        if a[j][i] == a[j+1][i]:
            f = True
print('CONTINUE' if f else 'GAMEOVER')