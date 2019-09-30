from copy import deepcopy
N,M=list(map(int, input().strip().split()))
abc={}
used={}
for _ in range(M):
    a,b,c=(list(map(int, input().strip().split())))
    abc[a,b]=c
    used[a,b]=False
spth=[[float("inf")]*(N+1) for _ in range(N+1)]
for i in range(1,N+1):
    spth[i][i]=0
for ab,c in abc.items():
    spth[ab[0]][ab[1]]=c
    spth[ab[1]][ab[0]]=c
for k in range(1,N+1):
    for i in range(1,N+1):
        for j in range(1,N+1):
            d=spth[i][k]+spth[k][j]
            if spth[i][j] > d:
                spth[i][j]=d

for ab,c in abc.items():
    for s in range(1,N+1):
        if used[ab]:break
        if spth[s][ab[1]]==spth[s][ab[0]]+c:
            used[ab]=True
            break
print(sum(not i for i in used.values()))