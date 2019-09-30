import sys
import fractions
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)

n = ni()
t = ni()
if n == 1:
    print(t)
else:
    for i in range(n - 1):
        tmp = ni()
        t = lcm(t, tmp)
    print(t)