n,x=map(int,input().split())
a=list(map(int,input().split()))
b=a[:]
d=sum(a)
for j in range(1,n):
    b=[min(b[i],a[i-j])for i in range(n)]
    d=min(d,sum(b)+j*x)
print(d)