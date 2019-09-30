from heapq import heappop, heappush
H,W,T=map(int,input().split())
INF=float("inf")
F=[[] for i in range(H)]
for i in range(H):
    s=list(input())
    F[i]=s
    for j in range(W):
        if s[j]=="S":
            sx,sy=i,j
        elif s[j]=="G":
            gx,gy=i,j

left,right=1,10**9
while right-left>1:
    mid=(left+right)//2
    D=[[INF]*W for i in range(H)]
    D[sx][sy]=0
    que=[(0,sx,sy)]
    while que:
        d,x,y=heappop(que)
        if D[x][y]<d:
            continue
        for dx,dy in [(0,1),(1,0),(-1,0),(0,-1)]:
            nx,ny=x+dx,y+dy
            if not (0<=nx<H and 0<=ny<W):
                continue
            cost=mid if F[nx][ny]=="#" else 1
            if D[nx][ny]>D[x][y]+cost:
                D[nx][ny]=D[x][y]+cost
                heappush(que,(D[nx][ny],nx,ny))
    if D[gx][gy]<=T:
        left=mid
    else:
        right=mid
print(left)