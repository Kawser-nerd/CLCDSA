N=int(input())
F=[list(map(int,input().split())) for _ in range(N)] #0-9
P=[list(map(int,input().split())) for _ in range(N)] #0-10

INF=10**9
ans=-INF

for i in range(1,2**10):
    tmpans=0
    for n in range(N):
        c=0
        for j in range(10):
            if (i>>j&1)&F[n][j]:
                c+=1
        tmpans+=P[n][c]

    ans=max(ans,tmpans)

print(ans)