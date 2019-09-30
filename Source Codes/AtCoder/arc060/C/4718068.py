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

from bisect import bisect

def main():
    N = II()
    X = LI()  # coordinate of hotels
    X.append(INF)  # banpei
    L = II()  # max move distance/day
    Q = II()
    AB = []  # two hotel (a,b)
    for _ in range(Q):
        AB.append(LI_())
    Unreachs = [[] for _ in range(N)]
    # 1day
    for i, x in enumerate(X[:-1]):
        u = bisect(X, x + L)
        Unreachs[i].append(u)
    # day 2, 4, 8, ...
    updated = True
    while updated:
        updated = False
        for i in range(N):
            u = Unreachs[Unreachs[i][-1] - 1][-1]
            updated = updated or (u != Unreachs[i][-1])
            Unreachs[i].append(u)
    # solve
    for a, b in AB:
        if a > b:
            a, b = b, a
        ans = 0
        while True:
            k = bisect(Unreachs[a], b) - 1
            if k < 0:
                ans += 1
                break
            ans += 2 ** k
            a = Unreachs[a][k] - 1
        print(ans)
    return 0

main()