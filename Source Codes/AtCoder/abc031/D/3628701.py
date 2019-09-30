import sys

K,N=map(int,input().split())
VW=[input().split() for i in range(N)]

import itertools

ITE=list(itertools.product(range(1,4),repeat=K))

for ite in ITE:
    SLIST=[None]*(K+1)
    flag=1
    for i in range(N):
        v,w=VW[i]

        LE=0
        for vw in v:
            LE+=ite[int(vw)-1]

        if LE!=len(w):
            flag=0
            break

        now=0
        for j in range(len(v)):
            if now>=len(w):
                flag=0
                break
            if SLIST[int(v[j])]!=None and w[now:now+ite[int(v[j])-1]]!=SLIST[int(v[j])]:
                flag=0
                break

            SLIST[int(v[j])]=w[now:now+ite[int(v[j])-1]]
            now+=ite[int(v[j])-1]

        if flag==0:
            break

    if flag==1:
        for s in SLIST[1:]:
            print(s)
        sys.exit()