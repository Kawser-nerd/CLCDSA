n,c = map(int,input().split())
x = []
v = []
for i in range(n):
    xx,vv = map(int,input().split())
    x.append(xx)
    v.append(vv)

a = [v[0]-x[0]] #a[i]:?????????x[i]?????????
for i in range(1,n):
    a.append(a[-1]+v[i] - x[i]+x[i-1])

b = [v[-1]-c+x[-1]] #?????
for i in range(1,n):
    b.append(b[-1]+v[n-1-i]-x[n-i]+x[n-1-i])



maxa = [a[0]]
maxb = [b[0]]
for i in range(1,n):
    maxa.append(max(maxa[-1],a[i]))
    maxb.append(max(maxb[-1],b[i]))

ass = 0
res = [0]
for i in range(n):
    if i != n-1:
        ass = a[i]+max(0,maxb[n-2-i]-x[i])
    else:
        ass = a[i]
    res.append(ass)



for i in range(n):
    if i != n-1:
        ass = b[i]+max(0,maxa[n-2-i]-(c-x[n-1-i]))
    else:
        ass = b[i]
    res.append(ass)
print(max(res))