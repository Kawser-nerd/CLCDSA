from  collections import deque
N=int(input())
P=[int(i) for i in input().split()]
inf = 10**20
table=[[0]*(N+2) for i in range(N+2)]
for i in range(1,N+1):
    if P[i-1]>0:
        table[i][N+1]=P[i-1]
    else:
        table[0][i]=-P[i-1]
    for j in range(2*i,N+1,i):
        table[i][j]=inf
        
def bfs(x):
    visit[x]=0
    h=deque()
    h.append(x)
    while h:
        y=h.popleft()
        for i in range(N+2):
            if visit[i]==-1 and table[y][i]>0:
                visit[i]=visit[y]+1
                h.append(i)
    return 0

def dinic(s,t,f):
    if s==t:
        return f
    for i in range(N+2):
        if visit[i]>visit[s] and table[s][i]>0:
            df = dinic(i,t,min(f,table[s][i]))
            if df>0:
                table[s][i]-=df
                table[i][s]+=df
                return df
    return 0

ans=0
while True:
    visit=[-1]*(N+2)
    bfs(0)
    #print(table,visit)
    if visit[N+1]==-1:
        break
    while True:
        df=dinic(0,N+1,inf)
        if df==0:
            break
        ans+=df
        #print(ans)
num=sum([p for p in P if p>0])
print(num-ans)