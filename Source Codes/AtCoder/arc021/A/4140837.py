inputs = [list(map(int, input().split())) for _ in range(4)]

flag = False
for i in range(4):
    for j in range(3):
        # ????????????????
        if inputs[i][j] == inputs[i][j+1] or inputs[j][i] == inputs[j+1][i]:
            flag = True

print('CONTINUE' if flag else 'GAMEOVER')