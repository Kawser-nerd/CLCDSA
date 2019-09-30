from itertools import permutations 
inf=10**9
n, m, r1 = map(int, input().split())
r=list(map(int, input().split()))
abc=[list(map(int, input().split())) for _ in range(m)]
d=[[inf]*n for i in range(n)]
for ai, bi, ci in abc:
    d[ai-1][bi-1]=ci
    d[bi-1][ai-1]=ci
for k in range(n):
    for i in range(n-1):
        for j in range(i, n):
            dk=d[i][k]+d[k][j]
            if d[i][j]>dk:
                d[j][i]=dk
                d[i][j]=dk
permutations(r)
ans=inf
for pi in permutations(r):
    res=0
    for i in range(r1-1):
        res+=d[pi[i]-1][pi[i+1]-1]
    if ans>res:
        ans=res
print(ans)