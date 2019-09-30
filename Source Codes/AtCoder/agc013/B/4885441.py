n,m,*t=map(int,open(0).read().split())
e=[[]for _ in range(n+1)]
for a,b in zip(t[::2],t[1::2]):
    e[a].append(b)
    e[b].append(a)
f=[0]*-~n
f[1]=1
a=[1]
while 1:
    for v in e[a[-1]]:
        if not f[v]:
            f[v]=1
            a.append(v)
            break
    else:
        break
b=[1]
while 1:
    for v in e[b[-1]]:
        if not f[v]:
            f[v]=1
            b.append(v)
            break
    else:
        break
a=a[:0:-1]+b
print(len(a),*a)