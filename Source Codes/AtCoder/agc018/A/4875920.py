from functools import reduce
N,K = map(int,input().split())
A = list(map(int,input().split()))
M = max(A)
def gcd(a, b): 
    while b:
        a, b = b, a % b
    return a
m = reduce(gcd,A)
if K <= M and K % m == 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')