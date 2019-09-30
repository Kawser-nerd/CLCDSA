H,W,T=map(int,input().split())

A=[list(map(int,input().split())) for i in range(H)]
#print(A)

ans=0
for i in range(H):
    for j in range(W):
        if (i+j)%2==T%2 and (i+j)<=T:
            ans=max(ans,A[i][j])
print(ans)