#??o?x??????????????????????????????????
#?????????1??true
#??????????????around???????????
#?Around?0?????around?????????+1????????
#???????????????????True?????False????

H,W = (10,10)
field = [list(input()) for _ in range(H)]
Around = [[0]*W for _ in range(H)]
cnt_islands = 0
def dfs(x,y):
    if x < 0 or x >= W or y < 0 or y >= H or field[y][x] == "r":
        return
    if field[y][x] == "x" :
        field[y][x] = "r"
        Around[y][x] += 1
        return
    #print("x={} y={}".format(x,y))
    field[y][x] = "r"

    dfs(x+1,y)
    dfs(x-1,y)
    dfs(x,y+1)
    dfs(x,y-1)

for y in range(H):
    for x in range(W):
        if field[y][x] == "o":
            for yr in range(H):
                for xr in range(W):
                    if field[yr][xr] == "r":
                        field[yr][xr] = "x"
            #for i in range(H):
            #    print(field[i])
            dfs(x,y)
            cnt_islands += 1

if cnt_islands == 1:
    print('YES')
else:
    f = False
    for y in range(H):
        for x in range(W):
            if Around[y][x] == cnt_islands:
                f = True
                print('YES')
                break
        if f :
            break
    if not f :
        print('NO')