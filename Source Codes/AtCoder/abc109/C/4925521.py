import fractions
from functools import reduce
def gcd_list(numbers):
    return reduce(fractions.gcd, numbers)

inpl = lambda: list(map(int,input().split()))
N, X = inpl()
x = inpl()
y = [ p - X for p in x ]
print(abs(gcd_list(y)))