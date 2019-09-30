N,K=map(int,input().split())
mod=1000000007

import math
import itertools
xr=math.ceil(math.sqrt(K))

LIST=[]#K??????
for i in range(1,xr+1):
    if K%i==0:
        LIST.append(i)
        LIST.append(K//i)

LIST=sorted(list(set(LIST)))

LEN=len(LIST)
LISTPRIME=[[LIST[i],0] for i in range(LEN)]#K?????????????
for i in range(1,LEN):
    if LISTPRIME[i][1]==1:
        continue
    
    x=LISTPRIME[i][0]
    
    for j in range(i+1,LEN):
        if LISTPRIME[j][1]==1:
            continue
        elif LISTPRIME[j][0]%x==0:
            LISTPRIME[j][1]=1
            
LISTP=[LISTPRIME[i][0]  for i in range(1,LEN) if LISTPRIME[i][1]==0]

#ANSLIST=[None]*len(LIST)

def iep(N,K,mod):#N???,K?1??????????????????.
    XPR=[]
    for l in LISTP:
        if l<=N and K%l==0:
            XPR.append(l)

    #print(XPR)
    lpr=len(XPR)
    ANS=0
    for ite in itertools.product(range(2),repeat=lpr):
        c=1
        for j in range(lpr):
            c=c*(XPR[j]**ite[j])
        #print(c,ite)
        SUM=(c+c*(N//c))*(N//c)//2
        ANS=ANS+((-1)**(sum(ite)%2))*SUM
        #print(ANS,SUM)
    #print(N,K,ANS)
        
    return ANS%mod

ANS=0
for l in LIST:
    ANS=(ANS+K*iep(N//l,K//l,mod))%mod
    #print("A",ANS)

print(ANS)