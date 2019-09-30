import fractions
import functools


_ = input()
A = list(map(int, input().split()))
print(functools.reduce(fractions.gcd, A))