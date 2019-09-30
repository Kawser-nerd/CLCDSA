from functools import reduce
from fractions import gcd

N,X=map(int, input().split())
print(reduce(gcd, [abs(X-int(x)) for x in input().split()]))