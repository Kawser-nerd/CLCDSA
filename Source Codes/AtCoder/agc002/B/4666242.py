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
    N, M = LI()
    XY = []
    for _ in range(M):
        XY.append(LI_())
    balls = [1] * N
    exp = set([0])
    for x, y in XY:
        balls[x] -= 1
        balls[y] += 1
        if x in exp:
            exp.add(y)
            if balls[x] == 0:
                exp.remove(x)
    ans = len(exp)
    return ans

print(main())