n,m=map(int,input().split())
E=[[] for _ in range(n)]
for _ in range(m):
    x,y=map(int,input().split())
    x-=1; y-=1
    E[x].append(y)
DP=[0]*(1<<n)
DP[0]=1
for bit in range(1<<n):
    for i in range(n):
        if bit&(1<<i)==0 and all(bit&(1<<j)==0 for j in E[i]):
            DP[bit|(1<<i)]+=DP[bit]
print(DP[-1])