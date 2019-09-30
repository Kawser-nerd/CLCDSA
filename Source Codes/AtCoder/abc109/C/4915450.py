import fractions
import sys

N, X = map(int, input().split())
x = list(map(int, input().split()))
x.sort()
dif = [abs(X-i) for i in x]
d_min = min(dif)

gcd = d_min
for i in dif:
    tmp = fractions.gcd(gcd, i)
    if tmp == 1:
        print(1)
        sys.exit()
    else:
        gcd = tmp

print(gcd)