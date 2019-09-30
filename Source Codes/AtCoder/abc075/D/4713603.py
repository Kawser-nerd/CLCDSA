n,k=map(int,input().split())
a=[list(map(int,input().split()))for i in range(n)]
a.sort()
b=float("inf")
for i in range(n-k+1):
    for j in range(i+k-1,n):
        p=a[j][0]-a[i][0]
        c=sorted([d[1] for d in a[i:j+1]])
        for s in range(j-i-k+2):
            q=c[s+k-1]-c[s]
            b=min(b,p*q)
print(b)