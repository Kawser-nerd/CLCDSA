def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
def inpl(): return [int(i) for i in input().split()]
from collections import defaultdict
H = defaultdict(lambda: 0)
N = int(input())
dot = [()]*N
mod = 998244353
for i in range(N):
    x, y = inpl()
    dot[i] = (x, y)
for i in range(N):
    for j in range(i+1,N):
        x1, y1 = dot[i]
        x2, y2 = dot[j]
        A = y1 - y2
        B = x2 - x1
        C = y1*x2 - x1*y2
        if A < 0:
            A *= -1
            B *= -1
            C *= -1
        gcdabc = gcd(gcd(A,B), C)
        A //= gcdabc
        B //= gcdabc
        C //= gcdabc
        H[(A, B, C)] += 1
ans = (2**N - N - 1 )%mod
for i in H.values():
    i = int((1+(1+8*i)**(1/2))/2)
    ans -= (2**i - i - 1)%mod
print(ans%mod)