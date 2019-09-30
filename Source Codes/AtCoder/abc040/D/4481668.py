N,M=map(int,input().split())
par=[-1]*N
roads=[]
for i in range(M):
    x,y,year=map(int,input().split())
    roads.append([x-1,y-1,year])

roads.sort(key=lambda x: x[2])
Q=int(input())
qs=[]

for i in range(Q):
    x,year=map(int,input().split())
    qs.append([x-1,year,i])
qs.sort(key=lambda x: x[1], reverse=True)

def root(x):
    if par[x]<0:
        return x
    else:
        par[x]=root(par[x])
        return par[x]

def getnum(x):
    return -par[root(x)]

def connect(x,y):
    rx=root(x)
    ry=root(y)
    if rx!=ry:
        if getnum(rx)<getnum(ry):
            rx,ry=ry,rx
        par[rx]+=par[ry]
        par[ry]=rx

for i in range(Q):
    while(len(roads)>0 and qs[i][1] < roads[-1][2] ):
        tmp=roads.pop()
        connect(tmp[0],tmp[1])
    qs[i][0]=getnum(qs[i][0])

qs.sort(key=lambda x:x[2])

for i in range(Q):
    print(qs[i][0])