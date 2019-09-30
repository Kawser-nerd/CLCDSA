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

from collections import Counter

def main():
    N = II()
    A = LI()
    idxs = [0] * (N + 1)
    for i, a in enumerate(A):
        idxs[a] = i
    ll = list(range(N + 1))
    rr = list(range(N + 1))
    ans = 0
    for a in range(N, 0, -1):
        idx = idxs[a]
        l, r = ll[idx], rr[idx]
        ans += (idx - l + 1) * (r - idx + 1) * a
        ll[r + 1] = l
        rr[l - 1] = r

    return ans

print(main())