H,W,N=map(int,input().split())
X=[0 for i in range(N)]
Y=[0 for i in range(N)]
D={}
for i in range(N):
    X[i],Y[i]=map(int,input().split())
    if X[i] in D:
        D[X[i]].add(Y[i])
    else:
        D[X[i]]={Y[i]}
ans=H
left=1;right=1
for x in range(2,H+1):
    if not(x in D):
        right=min(right+1,W)
    else:
        first=min(D[x])
        if left<=first and first<=right:
            ans=min(ans,x-1)
            break
        if first!=right+1:
            right=min(right+1,W)
print(ans)