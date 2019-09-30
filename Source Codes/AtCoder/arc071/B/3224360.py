ai = lambda: list(map(int, input().split()))

n,m = ai()
x = ai()
y = ai()
mod = 10**9+7

from itertools import accumulate as acc
sx = list(acc(x))
ssx = list(acc(x[::-1]))
sy = list(acc(y))
ssy = list(acc(y[::-1]))
    

a = sum(ssx[i] - sx[i] for i in range(n)) % mod
b = sum(ssy[i] - sy[i] for i in range(m)) % mod

print(a*b % mod)