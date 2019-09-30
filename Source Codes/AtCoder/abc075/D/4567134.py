n,k=map(int,input().split())
XY=[list(map(int,input().split())) for _ in range(n)]
XY.sort()
ans=float('inf')
for i in range(n):
    for j in range(i+1,n):
        x=XY[j][0]-XY[i][0]
        T=sorted(Z[1] for Z in XY[i:j+1])
        for u,v in zip(T,T[k-1:]):
            ans=min(ans,x*(v-u))
print(ans)