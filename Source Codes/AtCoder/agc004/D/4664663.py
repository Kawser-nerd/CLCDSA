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

from collections import defaultdict

def main():
    N, K = LI()
    A = LI_()
    edges = defaultdict(list)
    for i, a in enumerate(A[1:], 1):
        edges[a].append(i)

    global ans
    ans = 0
    if A[0] != 0:
        ans += 1
    def DFS(v, parent):
        global ans
        height = 0
        for to in edges[v]:
            height = max(height, DFS(to, v))
        if parent != 0 and height >= K - 1:
            height = -1
            ans += 1
        return height + 1
    DFS(0, 0)
    return ans

print(main())