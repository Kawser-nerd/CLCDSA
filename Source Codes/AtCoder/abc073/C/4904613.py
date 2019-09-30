n = int(input())
d = dict()
for i in range(n):
    x = int(input())
    if d.__contains__(x):
        d[x]+=1
    else:
        d[x]=1

res = 0

for v in d.values():
    if v%2:
        res+=1

print(res)