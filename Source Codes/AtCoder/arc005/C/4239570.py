from collections import deque
H,W=map(int,input().split())
c=[list(input()) for i in range(H)]
st=(-1,-1)
gl=(-1,-1)
for i in range(H):
    for j in range(W):
        if c[i][j]=="s":
            st=(i,j)
        if c[i][j]=="g":
            gl=(i,j)
q=deque([])
dist=[[-1 for i in range(W)] for i in range(H)]
dist[st[0]][st[1]]=0
q.append(st)
dx=[-1,1,0,0]
dy=[0,0,1,-1]
while(len(q)>0):
    r=q.popleft()
    x,y=r
    for k in range(4):
        nx=x+dx[k]
        ny=y+dy[k]
        if 0<=nx<H and 0<=ny<W:
            if dist[nx][ny]!=-1:
                continue
            if c[nx][ny]=="#":
                q.append((nx,ny))
                dist[nx][ny]=dist[x][y]+1
            else:
                q.appendleft((nx,ny))
                dist[nx][ny]=dist[x][y]

if dist[gl[0]][gl[1]]<=2:
    print("YES")
else:
    print("NO")