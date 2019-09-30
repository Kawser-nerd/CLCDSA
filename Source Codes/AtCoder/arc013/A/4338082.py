from functools import reduce
from itertools import permutations
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def di(A, B):
    return [a//b for a, b in zip(A, B)]


def mul(a, b):
    return a*b


def mu(A):
    return reduce(mul, A)


A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = 0
pe = permutations(B)

for a in pe:
    ans = max(ans, mu(di(A, a)))
print(ans)