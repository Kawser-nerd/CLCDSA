# coding:utf-8

import sys
from collections import deque, defaultdict

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    n, m = LI()

    G = defaultdict(list)
    S = defaultdict(set)
    for _ in range(m):
        a, b = LI_()
        G[a].append(b)
        G[b].append(a)
        S[a].add(b)
        S[b].add(a)

    res = deque([0, G[0][0]])
    visited = set(res)
    needs = S[res[0]] | S[res[-1]] - visited
    while needs:
        v = needs.pop()
        if v in visited:
            continue
        visited.add(v)
        if v in S[res[0]]:
            res.appendleft(v)
        else:
            res.append(v)
        needs = (S[res[0]] | S[res[-1]]) - visited

    print(len(res))
    print(*[v + 1 for v in res])


main()