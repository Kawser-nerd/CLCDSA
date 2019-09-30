from collections import deque
H,W = list(map(int,input().split()))
meiro = [list(input()) for l in range(H)]
for y, row in enumerate(meiro):
    try:
        try:
            posg = [y,row.index("g")]      
        except ValueError:
            pass
        poss = [y, row.index("s")]
    except ValueError:
        pass
dx = [1,0,-1,0]
dy = [0,1,0,-1]
stk = deque()
stk.append([poss[0],poss[1]])
dis =[[10**6 for i in range(W)] for l in range(H)]
dis[poss[0]][poss[1]]=0
while stk:
    x,y = stk.popleft()
    for i in range(4):
        xx,yy = x+dx[i],y+dy[i]
        if xx<0 or W<=yy or yy<0 or H<=xx:
            continue
        if meiro[xx][yy] ==".":
            if dis[x][y]<dis[xx][yy]:
                dis[xx][yy] = dis[x][y]
                stk.appendleft((xx,yy))
        elif meiro[xx][yy] =="g" :
            dis[xx][yy] = dis[x][y]
            if dis[xx][yy]<=2:
                print("YES")
                exit()
        elif meiro[xx][yy] =="#":
            if dis[x][y]+1<dis[xx][yy]:
                dis[xx][yy] = dis[x][y]+1
                stk.append((xx,yy))
print("NO")