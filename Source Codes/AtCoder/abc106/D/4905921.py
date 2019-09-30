from itertools import accumulate

N,M,Q=map(int,input().split())

a=[[0]*(N+1) for i in range(N+1)]
for i in range(M):
    L,R=map(int,input().split())
    a[L][R]+=1


b=[list(accumulate(a[i])) for i in range(N+1)]
k=[[b[j][i] for j in range(i+1) ] for i in range(N+1)]

ans=[list(accumulate(reversed(k[i])))[::-1] for i in range(N+1)]


for i in range(Q):
        p,q=map(int,input().split())
        print(ans[q][p-q-1])