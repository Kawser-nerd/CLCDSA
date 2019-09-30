N,K = map(int,input().split())
A = list(map(int,input().split()))
if K in A:
    print('POSSIBLE')
    exit()
if max(A) < K:
    print('IMPOSSIBLE')
    exit()

from fractions import gcd
g = A[0]
for a in A[1:]:
    g = gcd(g,a)
print('POSSIBLE' if K%g==0 else 'IMPOSSIBLE')