H,W = map(int,input().split())
L = [list(input()) for i in range(H)]

treated = [[False for w in range(W)] for h in range(H)]
ans = [["." for w in range(W)] for h in range(H)]
dxy = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]

for y in range(H) :
    for x in range(W) :
        cnt = 0
        for dy,dx in dxy :
            ny = y+dy
            nx = x+dx
            
            if (ny < 0) or (nx < 0) or (ny >= H) or (nx >= W) :
                cnt += 1
                continue
            if L[ny][nx] == "." :
                break
            cnt += 1
        if cnt == 8 :
            if L[y][x] == "." : continue
            treated[y][x] = True
            ans[y][x] = "#"
            for dy,dx in dxy :
                ny = y+dy
                nx = x+dx

                if (ny < 0) or (nx < 0) or (ny >= H) or (nx >= W) :
                    continue
                treated[ny][nx] = True

for y in range(H) :
    for x in range(W) :
        if L[y][x] == "." :
            treated[y][x] = True

for i in range(H) :
    if False in treated[i] :
        print("impossible")
        break
else :
    print("possible")
    for j in range(H) :
        print(*ans[j],sep="")