from heapq import heappush,heappop
K=int(input())
table=[[] for i in range(K)]
for i in range(K):
    table[i].append([1,(i+1)%K])
    t = (10*i)%K
    if t!=i:
        table[i].append([0,t])
dij=[]
visit=[False]*K
val=[10**9]*K
val[1]=0
heappush(dij,[0,1])
while dij:
    d,x=heappop(dij)
    if val[x]<d:
        continue
    for q,y in table[x]:
        if val[y]>val[x]+q:
            val[y]=val[x]+q
            heappush(dij,[val[y],y])
print(val[0]+1)