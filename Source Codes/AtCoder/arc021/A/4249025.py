A=[[int(i) for i in input().split()] for i in range(4)]
flag=0
for i in range(3):
    for j in range(4):
        if A[i][j]==A[i+1][j]:
            flag=1
for i in range(4):
    for j in range(3):
        if A[i][j]==A[i][j+1]:
            flag=1
if flag:
    print("CONTINUE")
else:
    print("GAMEOVER")