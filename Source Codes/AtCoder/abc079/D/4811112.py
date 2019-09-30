H,W=map(int,input().split())
C=[list(map(int,input().split())) for i in range(10)]
cost=[float('inf')]*10
cost[1]=0
check={1,}
while len(check)>0:
    now=check.pop()
    for i in range(10):
        if cost[i]>cost[now]+C[i][now]:
            cost[i]=cost[now]+C[i][now]
            check|={i,}
cost.append(0)
ans=0
for h in range(H):
    for a in map(int,input().split()):
        ans+=cost[a]
print(ans)