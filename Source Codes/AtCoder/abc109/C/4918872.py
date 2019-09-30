import fractions
from functools import reduce

def gcd(numbers):
    return reduce(fractions.gcd, numbers)

N, X = map(int, input().split())
x = list(map(int, input().split()))

dist = [abs(X - x[i]) for i in range(N)]
print(gcd(dist))