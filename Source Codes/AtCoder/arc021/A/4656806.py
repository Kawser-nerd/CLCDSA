A = [[int(_) for _ in input().split()] for _ in range(4)]
flag = False

for i in range(4):
    for j in range(3):
        if A[i][j] == A[i][j+1]:
            flag = True
            break
        if A[j][i] == A[j+1][i]:
            flag = True
            break

print("CONTINUE" if flag else "GAMEOVER")