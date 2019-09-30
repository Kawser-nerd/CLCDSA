n,h = map(int,input().split())

ken = []

res = 0

for i in range(n):
    a,b = map(int,input().split())
    ken.append((a,1))
    ken.append((b,0))

ken.sort(key = lambda x:x[0],reverse=True)


for d,f in ken:
    if f:
        if h%d:
            res += h//d + 1
        else:
            res += h//d
        h = 0
    else:
        res += 1
        h-=d
    if h<=0:
        print(res)
        exit(0)