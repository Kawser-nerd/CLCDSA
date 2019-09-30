def inside(x, y):
    return 0 <= x < 4 and 0 <= y < 4

a = [list(map(int,input().split())) for i in range(4)]

for i in range(4):
    for j in range(4):
        for x, y in [[0,1],[0,-1],[1,0],[-1,0]]:
            ii = i + x
            jj = j + y
            if not inside(ii, jj):
                continue
            if a[i][j] == a[ii][jj]:
                print('CONTINUE')
                exit()

print('GAMEOVER')