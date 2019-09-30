import queue
N,M=map(int,input().split())
G=[[1 for i in range(N)] for i in range(N)]
H=[[] for i in range(N)]
for i in range(N):
    G[i][i]-=1
for i in range(M):
    a,b=map(int,input().split())
    G[a-1][b-1]-=1
    G[b-1][a-1]-=1
for i in range(N):
    for j in range(N):
        if G[i][j]==1:
            H[i].append(j)
A=[[[],[]]]
k=0
q=queue.Queue()
reached=[0 for i in range(N)]
dist=[-1 for i in range(N)]
for i in range(N):
    if reached[i]==1:
        continue
    q.put(i)
    reached[i]=1
    dist[i]=0
    while(not(q.empty())):
        r=q.get()
        A[k][dist[r]].append(r)
        for p in H[r]:
            if reached[p]==0:
                q.put(p)
                dist[p]=(dist[r]+1)%2
                reached[p]=1
    k+=1
    A.append([[],[]])
for i in range(k):
    for j in range(2):
        for x in A[i][j]:
            for y in A[i][j]:
                if x==y:
                    continue
                if G[x][y]==1:
                    print(-1)
                    exit()
B=[]
for i in range(k):
    B.append((len(A[i][0]),len(A[i][1])))
dp=[[0 for i in range(N+1)] for i in range(k+1)]
dp[0][0]=1
for i in range(1,k+1):
    for j in range(N+1):
        if dp[i-1][j]==0:
            continue
        dp[i][j+B[i-1][0]]=1
        dp[i][j+B[i-1][1]]=1
delta=N
for i in range(N+1):
    if dp[k][i]==1:
        tmp=abs(N-2*i)
        if tmp<delta:
            delta=tmp
X=(N+delta)//2
Y=(N-delta)//2
print((X*(X-1)+Y*(Y-1))//2)