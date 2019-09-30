n,m=map(int,input().split())
A=[input() for _ in range(n)]
B=[input() for _ in range(m)]

ans='No'
flag=False
for i in range(n-m+1):
    for j in range(n-m+1):
        C=[A[i+k][j:j+m] for k in range(m)]
        if B==C:
            ans='Yes'
        
print(ans)