import sys
input = sys.stdin.readline

N,M=map(int,input().split())
ROAD=[list(map(int,input().split())) for i in range(M)]
Q=int(input())
Query=[list(map(int,input().split()))+[i] for i in range(Q)]

ROAD.sort(key=lambda x:x[2],reverse=True)
Query.sort(key=lambda x:x[1],reverse=True)
ROAD.append([0,0,0])

#UnionFind

Group=[[i,1] for i in range(N+1)]#??????.Group[i]=j???i?j???????
 
def find(x):#find(a)=find(b)?????????
    while Group[x][0] != x:
        x=Group[x][0]
    return x

def Union(x,y):#x?y??????????????
    if find(x) != find(y):
        Group[min(find(y),find(x))][1]=Group[find(x)][1]+Group[find(y)][1]
        Group[find(y)][0]=Group[find(x)][0]=min(find(y),find(x))


ry=0
qy=0
ANSLIST=[None]*Q
while qy<Q:
    v,w,ind=Query[qy]
    while w<ROAD[ry][2] and ry<M:
        Union(ROAD[ry][0],ROAD[ry][1])
        ry+=1
        

    ANSLIST[ind]=Group[find(v)][1]
    qy+=1


for a in ANSLIST:
    print(a)