n,x=map(int,input().split())
a=list(map(int,input().split()))
b=a[:]
d=sum(a)
for magic in range(n):
    b=[min(b[i],a[i-magic])for i in range(n)]
    d=min(d,sum(b)+magic*x)
print(d)