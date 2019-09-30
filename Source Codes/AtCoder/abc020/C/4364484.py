import heapq
H,W,T=map(int,input().split())
s=[list(input()) for i in range(H)]
st=(-1,-1)
gl=(-1,-1)
for i in range(H):
    for j in range(W):
        if s[i][j]=="S":
            st=(i,j)
        if s[i][j]=="G":
            gl=(i,j)
dx=[0,1,0,-1]
dy=[1,0,-1,0]
def check(inp):
    if inp<=1:
        return True
    q=[]
    heapq.heappush(q,(0,st))
    dist=[[-1 for j in range(W)] for i in range(H)]
    dist[st[0]][st[1]]=0
    while(len(q)>0):
        d,r=heapq.heappop(q)
        x,y=r
        for k in range(4):
            nx=x+dx[k]
            ny=y+dy[k]
            if not(0<=nx<H and 0<=ny<W):
                continue
            if dist[nx][ny]!=-1:
                continue
            if s[nx][ny]!="#":
                dist[nx][ny]=dist[x][y]+1
                heapq.heappush(q,(dist[nx][ny],(nx,ny)))
            else:
                dist[nx][ny]=dist[x][y]+inp
                heapq.heappush(q,(dist[nx][ny],(nx,ny)))
    if dist[gl[0]][gl[1]]<=T:
        return True
    else:
        return False


lo=1
hi=T
while(hi-lo>1):
    mi=(hi+lo)//2
    if check(mi):
        lo=mi
    else:
        hi=mi
print(lo)