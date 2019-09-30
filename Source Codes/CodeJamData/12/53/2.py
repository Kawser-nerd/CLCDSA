def check(m, f, p, v):
    d=m-f*v
    ans=0
    last=-1
    for i in p:
        if (i[1]<=last):
            continue
        if (d>=(i[1]-last)*i[0]*v):
            ans+=(i[1]-last)*v
            d-=(i[1]-last)*i[0]*v
        else:
            ans+=d//i[0]
            break
        last=i[1]
    return ans

def solve(m, f, n, data):
    p=[]
    for i in data:
        p.append( (int(i.split()[0]), int(i.split()[1])) )
    p.sort()
    l = 1
    r = m//f
    while r-l>10:
        f1 = (2*l + r)//3
        f2 = (l + 2*r)//3
        if (check(m, f, p, f1)>check(m, f, p, f2)):
            r = f2
        else:
            l = f1
    best = 0
    for i in range(l, r+1):
        best=max(best, check(m, f, p, i))
    return str(best)

f=open('input.txt', 'r')
data=f.read()
f.close()
data=data.split('\n')
t=int(data[0])
data=data[1:]
F=open('output1.txt', 'w')
for i in range(t):
    m, f, n = int(data[0].split()[0]), int(data[0].split()[1]), int(data[0].split()[2])
    F.write('Case #'+str(i+1)+': '+solve(m, f, n, data[1:(n+1)])+'\n')
    data=data[(n+1):]
F.close()
