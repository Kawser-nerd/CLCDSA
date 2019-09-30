n, k = map(int,input().split())
MOD = 10**9+7

def Devisor(x):
    l = []
    i = 1
    while i**2 <= x:
        if x%i == 0:
            l.append(i)
            l.append(x//i)
        i += 1
    return sorted(set(l))
 
def GCD(x, y):
    if y > x:
        x, y = y, x
    while y > 0:
        x, y = y, x%y
    return x

import collections
d = Devisor(k)
dd = collections.defaultdict(int)
ans = 0

for i in range(len(d)-1, -1, -1):
    x = d[i]
    y = n//x
    a = x*y*(y+1)//2 %MOD
    for j in range(i+1, len(d)):
        z = d[j]
        if z%x == 0:
            a -= dd[z]
    dd[x] = a
    ans += a*k//GCD(k, x)
    ans %= MOD
print(ans)