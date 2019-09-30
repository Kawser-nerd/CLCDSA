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

from itertools import product

def main():
    H, W = LI()
    A = []
    for _ in range(H):
        A.append(LI())
    ans = []
    for y, x in product(range(1, H + 1), range(1, W)):
        j, i = y - 1, x - 1
        if A[j][i] % 2:
            A[j][i + 1] += 1
            ans.append([y, x, y, x + 1])
    x = W
    i = x - 1
    for y in range(1, H):
        j = y - 1
        if A[j][i] % 2:
            A[j + 1][i] += 1
            ans.append([y, x, y + 1, x])
    print(len(ans))
    for arr in ans:
        print(*arr)

    return 0

main()