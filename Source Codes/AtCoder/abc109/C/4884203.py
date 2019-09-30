N,X=map(int,input().split())
xn = map(int, input().split())
dxn = [abs(x-X) for x in xn]
import fractions
from functools import reduce
print(reduce(fractions.gcd, dxn))