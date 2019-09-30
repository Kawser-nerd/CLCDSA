n,t = map(int,input().split())
a = list(map(int,input().split()))

p = a[n-1]
r = []

for i in range(n-1,-1,-1):
    if a[i] >= p:
        p = a[i]
    else:
        r.append(p-a[i])

res = r.count(max(r))

print(res)