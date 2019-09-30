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
    N, x = LI()
    A = [0] + LI()
    ans = 0
    for i in range(1, N + 1):
        red = A[i] + A[i - 1] - x
        if red > 0:
            ans += red
            A[i] -= red

    return ans

print(main())