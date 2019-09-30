import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()

from itertools import accumulate

def main():
    N, K = LI()
    A = LI()
    negs = [min(0, a) for a in A]
    poss = [max(0, a) for a in A]
    nacc = [0] + list(accumulate(negs))
    pacc = [0] + list(accumulate(poss))
    neg = max(q - p for p, q in zip(nacc, nacc[K:]))
    pos = min(q - p for p, q in zip(pacc, pacc[K:]))
    ans = sum(a for a in A if a > 0) + max(neg, -pos)

    return ans

print(main())