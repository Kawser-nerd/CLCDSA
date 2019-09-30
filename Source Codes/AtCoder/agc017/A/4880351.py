N,P = map(int,input().split())
A = list(map(int,input().split()))
A = [i%2 for i in A]
zero = A.count(0)
one = A.count(1)
ans = 0
def combinations(n, r):
    import math as ma
    return ma.factorial(n)//(ma.factorial(n-r)*ma.factorial(r))

if P == 0:
    ans += 2**zero
    a = 0
    for i in range(one//2):
        a += combinations(one, 2*(i+1))
    ans += a*(2**zero)
else:
    ans += 2**zero
    a = 0
    for i in range(one//2):
        a += combinations(one, 2*(i+1))
    ans += a*(2**zero)
    ans = 2**N - ans
print(ans)