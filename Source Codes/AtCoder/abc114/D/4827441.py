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
from collections import Counter

def main():
    N = II()
    factors = Counter()
    for k in range(1, N + 1):
        for i in (2,3,5,7):
            while k % i == 0:
                factors[i] += 1
                k //= i
        if k != 1:
            factors[k] += 1
    # 75 = 3 * 5 * 5
    nfactors = sorted(factors.values())
    ans = 0
    dp = [0] * 76
    dp[1] = 1
    for cnt in nfactors:
        pre = dp
        dp = [0] * 76
        for c in range(1, cnt + 2):
            for k in range(75 // c + 1):
                dp[k * c] += pre[k]
    ans = dp[75]
    return ans

print(main())