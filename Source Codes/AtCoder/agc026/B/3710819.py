def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
def inpl(): return [int(i) for i in input().split()]
T = int(input())
for _ in range(T):
    A, B, C, D = inpl()
    if A < B or B > D:
        print('No')
        continue
    if C >= B:
        print('Yes')
        continue
    gcdbd = gcd(B, D)
    if (1+(C-A%B)//gcdbd)*gcdbd+A%B >= B:
        print('Yes')
    else:
        print('No')