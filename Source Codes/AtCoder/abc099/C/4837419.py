from collections import Counter
from functools import reduce
import fractions
import math
import statistics
import sys
import time
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
def LI(): return [int(x) for x in sys.stdin.readline().split()]  # LIST INT
def LF(): return [float(x) for x in sys.stdin.readline().split()]  # LIST FLOAT
def LS(): return sys.stdin.readline().split()  # LIST STRING
def MI(): return map(int, sys.stdin.readline().split())  # MAP INT
def II(): return int(sys.stdin.readline())  # INPUT INT
def IS(): return input()  # INPUT STRING
def P(x): return print(x)
def C(x): return Counter(x)
def GCD_LIST(numbers):  # greatest common divisor
    return reduce(fractions.gcd, numbers)
def LCM_LIST(numbers):  # least common multiple
    return reduce(LCM, numbers)
def LCM(m, n):
    return (m * n // fractions.gcd(m, n))


# n = II()
# one = [1]
# six = [6 ** i for i in range(1, 6+1)]
# nine = [9 ** i for i in range(1, 5+1)]
# numbers = one + six + nine
# numbers.sort(reverse=True)

N = int(input())
dp = [INF] * 100001
dp[0], dp[1] = 0, 1
L = [1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049]
# dp[n]??n??????????????
for i in range(2, 100001):
    for j in range(len(L)):
        if i-L[j] >= 0:
            dp[i] = min(dp[i-L[j]]+1, dp[i])
# 100???????????100-L[0] = 100-1=99?1???????????????
# dp[100]???min(dp[99]+1?INF)?99?????????????????1????1?????
# ????
# ????????94??????????????+1?????dp[99]??????????????
# 100000 * 10??? 1000000???
print(dp[N])