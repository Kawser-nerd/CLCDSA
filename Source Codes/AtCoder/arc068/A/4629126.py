import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
from functools import partial, reduce
from operator import mul
prod = partial(reduce, mul)
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()

def main():
    x = II()
    ans = x // (6 + 5) * 2
    x %= (6 + 5)
    if 0 < x <= 6:
        ans += 1
    elif 6 < x <= 11:
        ans += 2
    return ans

print(main())