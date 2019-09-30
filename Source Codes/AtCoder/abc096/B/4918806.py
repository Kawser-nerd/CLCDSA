from collections import Counter
from functools import reduce
import fractions
import math
import statistics
import sys
import time
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
def LI(): return [int(x) for x in sys.stdin.readline().split()]  # LIST INT
def LF(): return [float(x) for x in sys.stdin.readline().split()]  # LIST FLOAT
def LS(): return sys.stdin.readline().split()  # LIST STRING
def MI(): return map(int, sys.stdin.readline().split())  # MAP INT
def II(): return int(sys.stdin.readline())  # INPUT INT
def IS(): return input()  # INPUT STRING
def P(x): return print(x)
def C(x): return Counter(x)
def GCD_LIST(numbers):  # greatest common divisor
    return reduce(fractions.gcd, numbers)
def LCM_LIST(numbers):  # least common multiple
    return reduce(LCM, numbers)
def LCM(m, n):
    return (m * n // fractions.gcd(m, n))


li = LI()
k = II()
ans = []

def calc(a, b, c, count):

    if count == k:
        val = a+b+c
        ans.append(val)
        count -= 1
        return

    count += 1
    calc(a*2, b, c, count)
    calc(a, b*2, c, count)
    calc(a, b, c*2, count)


calc(li[0], li[1], li[2], 0)
print(max(ans))
# ???