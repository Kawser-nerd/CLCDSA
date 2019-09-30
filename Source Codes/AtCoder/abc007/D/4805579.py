# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

OK = [0, 1, 2, 3, 5, 6, 7, 8]


def cnt(N):
    L = len(N)
    dp = [[0]*2 for _ in range(L+1)]
    N = "".join(list(reversed([c for c in N])))
    dp[0][1] = 1
    for dig in range(L):
        for less in range(2):
            for new in OK:
                leq = new < int(N[dig]) or (less == 1 and int(N[dig]) == new)
                dp[dig+1][leq] += dp[dig][less]
    return dp[L][1]


def solve():
    A, B = input().split()

    noKinsi = cnt(B)-cnt(str(int(A)-1))
    ans = int(B)-int(A) - noKinsi+1
    print(ans)


solve()