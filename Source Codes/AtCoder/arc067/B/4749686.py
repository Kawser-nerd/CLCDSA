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
    N, A, B = LI()
    X = LI()
    ans = 0
    for x, y in zip(X, X[1:]):
        if (y - x) * A < B:
            ans += (y - x) * A
        else:
            ans += B
    return ans

print(main())