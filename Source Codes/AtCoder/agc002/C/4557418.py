n,l=map(int,input().split())
a=list(map(int,input().split()))
mu=[0]*(n-1)
for i in range(n-1):
    mu[i]=a[i]+a[i+1]
if max(mu)<l:
    print("Impossible")
else:
    print("Possible")
    s=mu.index(max(mu))
    for i in range(1,s+1):
        print(i)
    for i in range(n-1,s,-1):
        print(i)