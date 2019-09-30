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

def main():
    N = II()
    A = LI()
    from collections import Counter
    cnt = Counter(A)
    if N % 2 and cnt[0] < 0:
        return 0
    for i in range(N % 2 + 1, N, 2):
        if cnt[i] != 2:
            return 0
    ans = (2 ** (N // 2)) % MOD

    return ans

print(main())