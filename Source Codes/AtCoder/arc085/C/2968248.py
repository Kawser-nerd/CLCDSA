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
#print(table)
def fk(x,t,f):
    #print(x)
    visit[x]=True
    if x==t:
        return f
    for i in range(N+2):
        if (not visit[i]) and table[x][i]>0:
            df=fk(i,t,min(f,table[x][i]))
            if df>0:
                table[x][i]-=df
                table[i][x]+=df
                return df
    return 0

ans=0
while True:
    visit=[False]*(N+2)
    df=fk(0,N+1,inf)
    if df>0:
        ans+=df
    else:
        break
num=sum([p for p in P if p>0])
print(num-ans)