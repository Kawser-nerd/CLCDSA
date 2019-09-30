n=int(input())
a=[0]+list(map(int,input().split()))
a+=[0]

cost=0
pre=0
for i in range(n+2):
    cost+=abs(a[i]-pre)
    pre=a[i]
#print(a,cost)
for i in range(n):
    if (a[i]-a[i+1])*(a[i+1]-a[i+2])<0:
        print(cost-2*(min(abs(a[i]-a[i+1]),abs(a[i+1]-a[i+2]))))
    else:
        print(cost)