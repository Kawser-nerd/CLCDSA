maps = [list(map(int,input().split()))+[0] for i in range(4)] + [[0]*5]
for i in range(4):
    for j in range(4):
        if maps[i][j] == maps[i+1][j] or maps[i][j] == maps[i][j+1]:
            print("CONTINUE")
            exit()
else:
    print("GAMEOVER")