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
    N = II()
    P = LI()
    T = [1] * N
    for i, p in enumerate(P):
        T[p - 1] += i
    A = list(accumulate(T))
    B = list(accumulate(T[::-1]))[::-1]
    print(*A)
    print(*B)

    return 0

main()