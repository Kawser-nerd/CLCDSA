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
    A = []
    for _ in range(N):
        A.append(II())
    ans = 0
    tmp = 0
    for a in A:
        if a > 0:
            tmp += a
        else:
            ans += tmp // 2
            tmp = 0
    ans += tmp // 2

    return ans

print(main())