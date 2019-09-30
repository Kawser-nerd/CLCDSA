n = int(input())

c =[]
s =[]
f =[]

for i in range(n-1):
    x,y,z = map(int,input().split())
    c.append(x)
    s.append(y)
    f.append(z)

for i in range(n-1):
    t = 0
    for j in range(i,n-1):
        if t <= s[j]:
            w = s[j]-t 
        else:
            w = (f[j] - (t-s[j])%f[j])%f[j]
        t+=w
        t+=c[j]
    print(t)

print(0)