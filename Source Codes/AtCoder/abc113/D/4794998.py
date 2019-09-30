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

fibo = [1, 1]
for i in range(2, 9):
    fibo.append(fibo[i - 1] + fibo[i - 2])

def main():
    H, W, K = LI()
    K -= 1
    dp = [0] * W
    dp[0] = 1
    for _ in range(H):
        pre = dp
        dp = [0] * W
        for w in range(W):
            # down
            cnt = fibo[max(0, w - 0)] * fibo[max(0, W - w - 1)]
            dp[w] += pre[w] * cnt
            dp[w] %= MOD
            # to L
            cnt = fibo[max(0, w - 1)] * fibo[max(0, W - w - 1)]
            if w - 1 >= 0:
                dp[w - 1] += pre[w] * cnt
                dp[w - 1] %= MOD
            # to R
            cnt = fibo[max(0, w - 0)] * fibo[max(0, W - w - 2)]
            if w + 1 < W:
                dp[w + 1] += pre[w] * cnt
                dp[w + 1] %= MOD
    ans = dp[K]
    return ans

print(main())