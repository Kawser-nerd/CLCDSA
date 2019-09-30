import sys
input = sys.stdin.readline
from functools import reduce
from fractions import gcd
def gcd_list(numbers):
    return reduce(gcd, numbers)
n,k = map(int,input().split())
A = list(map(int,input().split()))
if k % gcd_list(A) == 0 and k <= max(A):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")