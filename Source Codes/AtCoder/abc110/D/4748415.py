n,m = map(int, input().split())
import math
import collections
def tds(n):
    prime_count = collections.Counter()
    
    for i in range(2, int(math.sqrt(n)) + 2):
        while n % i == 0:
            n /= i
            prime_count[i] += 1
    if n > 1:
        prime_count[n] += 1
    
    return prime_count
c=tds(m)
ans=1
def C(n,r):
    res=1
    for i in range(n,n-r,-1):
        res*=i
    return res//math.factorial(r)
for ci in c.values():
    ans*=C(n+ci-1,ci)
    ans%=10**9+7
print(int(ans))