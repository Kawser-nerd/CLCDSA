L = []
for h in range(4) :
    L.append(list(map(int,input().split())))

dxy = [(-1,0), (1,0), (-0,-1), (0,1)]
ans = "GAMEOVER"
explore = 1

for y in range(4) :
    if not explore :
        break
    for x in range(4) :
        if not explore :
            break
        for dy,dx in dxy :
            ny = y+dy
            nx = x+dx
            
            if (ny < 0) or (ny >= 4) or (nx < 0) or (nx >= 4) :
                continue
            if L[y][x] == L[ny][nx] :
                ans = "CONTINUE"
                explore = 0
                break
print(ans)