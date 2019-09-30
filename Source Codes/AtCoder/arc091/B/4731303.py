n,k=map(int,input().split())
c=0
for i in range(n,k,-1):
    p=n//i
    c+=(i-k)*p+(max(0,n-p*i-k+1) if k!=0 else n-p*i-k)
print(c)