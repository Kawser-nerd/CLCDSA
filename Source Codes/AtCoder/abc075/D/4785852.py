N,K=map(int,input().split())
ans=float('inf')
point=[tuple(map(int,input().split())) for i in range(N)]
point.sort(key=lambda x:x[0])
for i in range(N-K+1):
    for j in range(i+K,N+1):
        check=point[i:j]
        x=check[-1][0]-check[0][0]
        check.sort(key=lambda x:x[1])
        for k in range(j-i-K+1):
            y=check[k+K-1][1]-check[k][1]
            ans=min(ans,x*y)
print(ans)