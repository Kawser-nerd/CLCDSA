n,x=map(int,input().split())
a=list(map(int,input().split()))
c=0
for i in range(1,n):
    p=a[i-1]+a[i]
    c+=max(0,p-x)
    a[i]=max(0,a[i]-max(0,p-x))
print(c)