n,q = map(int,input().split())
a=[]
for p in range(n+1):
    a.append(0)
s=[]
for i in range(q):
    s.append(list(map(int,input().split())))

for j in range(q):
    for k in range(s[j][0],s[j][1]+1):
        a[k]=s[j][2]

a.remove(0)
for h in range(n):
    print(a[h])