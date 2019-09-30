N,x=[int(i)for i in input().split()]
a=[int(i)for i in input().split()]

cnt=0
for i in range(N):
    if a[i]>x:
        cnt+=a[i]-x
        a[i]=x
for i in range(1,N):
    su = a[i-1]+a[i]
    if su>x:
        sub=su-x
        a[i]-=sub
        cnt+=sub
print(cnt)