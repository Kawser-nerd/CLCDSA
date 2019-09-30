def serch(x,y,p):
    if x<0 or W<=y or y<0 or H<=x or meiro[x][y] =="#":
        return
    if memo[x][y]:
        p = [x,y]
        return
    memo[x][y] = 1
    kyo[x][y] = kyo[p[0]][p[1]] + 1
    p = [x,y]
    serch(x+1,y,p)
    serch(x-1,y,p)
    serch(x,y+1,p)
    serch(x,y-1,p)
H,W = list(map(int,input().split()))
sx,sy = 0,0
gx,gy = H-1,W-1
meiro = [list(input()) for l in range(H)]
counter = 0
for a in range(H):
    for b in range(W):
        n = 1 if meiro[a][b] =="." else 0
        counter += n
dx = [1,0,-1,0]
dy = [0,1,0,-1]
stk = [(sx,sy)]

memo =[[0 for i in range(W)] for l in range(H)]
memo[sx][sy]=1
dis =[[0 for i in range(W)] for l in range(H)]
while stk:
    x,y = stk.pop(0)
    for i in range(4):
        xx,yy = x+dx[i],y+dy[i]
        if xx<0 or W<=yy or yy<0 or H<=xx or meiro[xx][yy] =="#" or memo[xx][yy]==True:
            continue
        dis[xx][yy] = dis[x][y]+1
        stk.append((xx,yy))
        memo[xx][yy] = 1
if dis[gx][gy]==0:
    print(-1)
else:
    print(counter-dis[gx][gy]-1)