a=list(map(int,input().split()))
sum=0
sum+=a.count(a[0])+a.count(a[1])+a.count(a[2])
if sum==3:
    print(3)
elif sum==5:
    print(2)
else:
    print(1)