from collections import deque
K=int(input())
table=[[] for i in range(K)]
for i in range(K):
    table[i].append([1,(i+1)%K])
    t = (10*i)%K
    if t!=i:
        table[i].append([0,t])
dij=deque()
visit=[False]*K
val=[10**9]*K
val[1]=0
dij.append([0,1])
while dij:
    d,x=dij.popleft()
    if val[x]<d:
        continue
    for q,y in table[x]:
        if val[y]>val[x]+q:
            val[y]=val[x]+q
            if q==1:
                dij.append([val[y],y])
            else:
                dij.appendleft([val[y],y])
print(val[0]+1)