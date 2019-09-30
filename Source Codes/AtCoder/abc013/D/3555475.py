N,M,D = map(int,input().split())
A = list(map(int,input().split()))
a = [i for i in range(N)]
for i in range(M):
    swap = A[i]-1
    a[swap],a[swap+1]=a[swap+1],a[swap]

f = [i for i in range(N)]
for i in range(N):
    f[a[i]] = i

ans = [i for i in range(N)]
while D:
    if D%2 == 1:
        ans = [f[ans[i]] for i in range(N)]
    f = [f[f[i]] for i in range(N)]
    D >>= 1

for i in range(N):
    print(ans[i]+1)