n,k=map(int,input().split())
m=10**9+7
c=1
if n>k:s,r=n+k-1,k
else:s,r=n,k%n
for i in range(r):c*=(s-i)*pow(i+1,m-2,m)%m
print(c%m)