import sys

N,D=map(int,input().split())
X,Y=map(int,input().split())

Combi=[[] for i in range(N+1)]
Combi[0]=[1,0]

for i in range(1,N+1):
    Combi[i].append(1)
    for j in range(i):
        Combi[i].append(Combi[i-1][j]+Combi[i-1][j+1])
    Combi[i].append(0)


if X%D!=0 or Y%D!=0:
    print(0)
    sys.exit()

x=abs(X//D)
y=abs(Y//D)

#r-l=x
#u-d=y
#r+l+u+d=N

ANS=0
for r in range(N+1):
    l=r-x
    if l<0:
        continue
    for u in range(N-r-l+1):
        d=u-y
        if d<0:
            continue
        if r+l+u+d==N:
            ANS+=Combi[N][r]*Combi[N-r][l]*Combi[N-r-l][u]
            #print(r,l,u,d)


print(ANS/(4**N))