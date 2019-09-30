a,b,k = map(int,input().split())
res = []
for i in range(a,min(a+k,b)):
    res.append(i)
for j in range(max(a,b-k+1),b+1):
    res.append(j)
res = sorted(set(res))
for i in res:
    print(i)