import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
def POW(x, y):
    if y == 0:
        return 1
    elif y == 1:
        return x
    elif y % 2 == 0:
        return POW(x, y // 2) ** 2 % MOD
    else:
        return POW(x, y // 2) ** 2 * x % MOD
def mod_factorial(x, y): return x * POW(y, MOD - 2) % MOD
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()
from functools import reduce

def main():
    N, M = LI()
    if N >= M // 2:
        return M // 2
    rem = M - 2 * N
    ans = N + rem // 4
    return ans

print(main())