A = [list(map(int, input().split())) for _ in range(4)]

flag = False
for i in range(4):
    for j in range(4):
        if j != 3:
            if A[i][j] == A[i][j+1]:
                flag = True
                
        if i != 3:
            if A[i][j] == A[i+1][j]:
                flag = True
            
if flag:
    print('CONTINUE')
else:
    print('GAMEOVER')