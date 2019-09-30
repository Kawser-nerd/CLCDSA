from bisect import bisect
n = int(input())
d = [int(input()) for i in range(n)]
a,d,mod,ans = [],sorted(d),10**9+7,0
for i in range(n): a.append(n-bisect(d,d[i]*2-1))
for i in range(n-2,-1,-1): a[i]+=a[i+1]
for i in range(n): ans = (ans+bisect(d,d[i]//2)*a[min(n-1,bisect(d,d[i]*2-1))])%mod
print(ans)