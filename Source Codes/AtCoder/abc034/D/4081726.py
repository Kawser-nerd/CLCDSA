N,K=map(int,input().split())
WP=[list(map(int,input().split())) for i in range(N)]

def dense(w1,p1,w2,p2):
    return w1+w2,(w1*p1+w2*p2)/(w1+w2)


nw=0
np=0
check=[0]*N
for test in range(K):
    ANS=0
    for i in range(N):
        if check[i]==1:
            continue
        neww,newp=dense(nw,np,WP[i][0],WP[i][1])

        if ANS<newp:
            ANS=newp
            nextw=neww
            nextind=i

    check[nextind]=1
    nw=nextw
    np=ANS

print(ANS)