from math import pi
from math import sin
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

A, B, C = map(int, input().split())


def f(t):
    return A*t+B*sin(C*t*pi)-100


e = 10**(-7)


def check(y):
    if abs(y) <= e:
        return True
    else:
        False


lower = 0
upper = 100
mid = (lower+upper)/2

# while not check(mid):
for _ in range(10**4):
    mid = (upper+lower)/2
    yl = f(lower)
    ym = f(mid)
    yu = f(upper)

    if yl*ym >= 0:
        lower = mid
    else:
        upper = mid
print(mid)