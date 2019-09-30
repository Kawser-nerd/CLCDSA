from fractions import gcd
X,Y = map(int,input().split('/'))
g = gcd(X,Y)
X //= g
Y //= g

ok = 10**18
ng = 0
while ok-ng > 1:
    mid = (ok+ng+1)//2
    n = mid*Y
    m = n*(n+1)//2 -X*mid
    if m > 0:
        ok = mid
    else:
        ng = mid

ans = []
k = ok
while True:
    n = k*Y
    m = n*(n+1)//2 - X*k
    if 1 <= m <= n:
        ans.append(str(n) + ' ' + str(m))
    elif m > n:
        break
    k += 1

if ans:
    print(*ans, sep='\n')
else:
    print('Impossible')