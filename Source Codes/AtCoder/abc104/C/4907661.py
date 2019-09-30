import math

D,G=map(int,input().split())
a=[list(map(int,input().split())) for i in range(D)]

ans=100000
for i in range(2**D):
    s=bin(i)[2:].zfill(D)
    x=[int(s[i]) for i in range(D)]
    q,score=0,G
    for i in range(D):
        if x[i]==1:
            q+=a[i][0]
            score -= a[i][0]*(i+1)*100 + a[i][1]


    if score>0:
        for i in range(D-1,-1,-1):
            if x[i]==0:
                k=(a[i][0]-1)*(i+1)*100
                if k>=score:
                    q+= math.ceil( score/((i+1)*100) )
                    score=-1
                    break

                else:
                    q+=a[i][0]-1
                    score-= (a[i][0]-1)*(i+1)*100
        
    if score<=0: ans=min(ans,q)


print(ans)