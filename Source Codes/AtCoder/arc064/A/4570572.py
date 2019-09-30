n,x,*a=map(int,open(0).read().split())
ans=sum(a)
for i in range(n-1):
    tyouka=a[i]+a[i+1]-x
    if tyouka>0:
        if tyouka<=a[i+1]:
            a[i+1]=a[i+1]-tyouka
        else:
            a[i]=a[i]+a[i+1]-tyouka
            a[i+1]=0
print(ans-sum(a))