a=[list(map(int,input().split()))+[0]for i in range(4)]+[[0]*5]
for i in range(4):
    for j in range(4):
        if a[i][j]==a[i+1][j] or a[i][j]==a[i][j+1]:
            print("CONTINUE")
            exit()
else:
    print("GAMEOVER")