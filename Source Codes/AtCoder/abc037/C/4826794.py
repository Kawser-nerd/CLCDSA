n,k=map(int,input().split())
X=list(map(int,input().split()))
C=sum(X[:k])
ans=sum(X[:k])
for i in range(0,n-k):
    C-=X[i]
    C+=X[i+k]
    ans+=C

    
print(ans)