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
    N, M = LI()
    edges = defaultdict(list)
    for _ in range(M):
        a, b = LI_()
        edges[a].append(b)
        edges[b].append(a)
    quads = []
    large = 0
    for i, e in edges.items():
        c = len(e)
        if c % 2 == 1:
            return 'No'
        if c >= 6:
            large += 1
        if c == 4:
            quads.append(i)
    if large > 0:
        return 'Yes'
    if len(quads) > 2:
        return 'Yes'
    if len(quads) < 2:
        return 'No'
    for v in edges[quads[0]]:
        visited = [0] * N
        visited[quads[0]] = 1
        while v != quads[1]:
            visited[v] = 1
            for to in edges[v]:
                if visited[to] == 0:
                    v = to
                    break
            if visited[v] == 1:
                break
        if v != quads[1]:
            return 'Yes'

    return 'No'

print(main())