import math
n,m=map(int,input().split())
if abs(n-m)>1:print(0);exit()
ans=(math.factorial(n)*math.factorial(m))%(10**9+7)
if n==m:ans*=2;ans%=10**9+7
print(ans)