def ans():
    board=[[int(i) for i in input().split()] for _ in range(4)]
    pattarn=[(1,0),(-1,0),(0,1),(0,-1)]
    for i in range(4):
        for j in range(4):
            for x,y in pattarn:
                try:
                    if i+y<0 or j+x<0:
                        pass
                    elif board[i+y][j+x]==board[i][j]:
                        return "CONTINUE"
                except:
                    pass
    return "GAMEOVER"

if __name__=="__main__":
    print(ans())