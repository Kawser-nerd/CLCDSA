N,M = map(int,input().split())
ds = [int(input()) for i in range(M)]

ans = list(range(1,N+1))
now = 0
for d in ds:
    if d in ans:
        i = ans.index(d)
        ans[i] = now
    now = d
print(*ans,sep='\n')