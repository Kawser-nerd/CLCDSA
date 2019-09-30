n,m=list(map(int,input().split()))
a=[int(input())for i in range(m)][::-1]
c=[0]*(n+1)
for i in range(m):
    if c[a[i]]==0:
        print(a[i])
        c[a[i]]=1
for i in range(1,n+1):
    if c[i]!=1:
        print(i)