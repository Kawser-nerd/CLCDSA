n,a,b=map(int,input().split())
v=list(map(int,input().split()))
v.sort()
def f(x,y):
    c=1
    d=1
    for i in range(x):
        c*=(i+1)
        d*=(y-i)
    return d//c
p=v[n-a:]
g=sum(p)/a
print(sum(p)/a)
w=0
for i in range(a,b+1):
    p=v[n-i:]
    h=sum(p)/i
    if h<g:
        break
    else:
        q=p[0]
        d=v.count(q)
        e=p.count(q)
        w+=f(e,d)
print(w)