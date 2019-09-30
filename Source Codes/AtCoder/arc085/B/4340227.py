n,z,w = map(int,input().split())
a = tuple(map(int,input().split()))

res = abs(a[-1]-w)
for i in range(n-1):
    cand = abs(a[-1]-a[i])
    for j in range(i+1,n-1):
        cand = min(a[j]-a[-1],cand)
    res = max(res,cand)
print(res)