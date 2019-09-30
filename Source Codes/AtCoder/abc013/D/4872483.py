n,m,d=map(int,input().split())
a=list(map(int,input().split()))
h=[i for i in range(n)]
for i in range(m):
    h[a[i]-1],h[a[i]]=h[a[i]],h[a[i]-1]
b=[0]*n
for i in range(n):
    b[h[i]]=i
o=[i for i in range(n)]
while d:
    if d%2==1:
        o=[b[o[i]]for i in range(n)]
    b=[b[b[i]]for i in range(n)]
    d>>=1
for i in o:
    print(i+1)