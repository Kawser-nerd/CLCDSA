N=int(input())
BR=[list(map(int,input().split())) for i in range(N-1)]
mod=10**9+7

BRLIST=[[] for i in range(N+1)]

for x,y in BR:
    BRLIST[x].append(y)
    BRLIST[y].append(x)

from collections import deque
QUE = deque()

ANS=[[0,0] for i in range(N+1)]
USED=[0]*(N+1)
for i in range(1,N+1):
    if len(BRLIST[i])==1:
        QUE.append(i)



while QUE:
    x=QUE.pop()
    if USED[x]==1:
        continue
    #print(x,QUE,USED,ANS)
    NOUSES=0
    for j in BRLIST[x]:
        if USED[j]==0:
            NOUSES+=1
    if NOUSES>=2:
        QUE.appendleft(x)
        continue


    W=1
    B=1
    for j in BRLIST[x]:
        if USED[j]!=0:
            W=W*(ANS[j][0]+ANS[j][1])%mod
            B=B*ANS[j][0]%mod

        else:
            QUE.appendleft(j)
    ANS[x]=[W,B]
    USED[x]=1

print(sum(ANS[x])%mod)