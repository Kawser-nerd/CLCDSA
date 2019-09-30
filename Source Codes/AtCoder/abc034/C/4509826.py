W,H = map(int,input().split())
M = 10**9+7
a = 1
b = 1
def func(a,b,p):
    if b == 0:
        return 1
    elif b % 2 == 0:
        return (func(a,b//2,p)**2) % p
    else:
        return (a*func(a,b-1,p)%p)

for i in range(1,W):
    b *= i
    if b > M:
        b = b%M
for i in range(H,W+H-1):
    a *= i
    if a > M:
        a = a % M

print((a*func(b,M-2,M))%M)