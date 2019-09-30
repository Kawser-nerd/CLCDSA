n,m=map(int,input().split())
a=[i for i in range(1,n+1)]
d=0
for i in range(m):
    c=int(input())
    if c!=d:
        a[a.index(c)]=d
        d=c
for i in a:
    print(i)