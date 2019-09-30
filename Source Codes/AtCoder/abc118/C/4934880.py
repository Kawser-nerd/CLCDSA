import fractions
from functools import reduce

def gcd_list(numbers):
    return reduce(fractions.gcd, numbers)

N = int(input())
A = list(map(int, input().split()))

print(gcd_list(A))