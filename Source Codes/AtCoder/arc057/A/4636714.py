from math import log,ceil
a,k=map(int,input().split())
m=2*10**12
if k==0:
    ans=m-a
else:
    x=(m+1/k)/(a+1/k)
    ans=ceil(log(x)/log(1+k))
print(ans)