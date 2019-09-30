import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from fractions import Fraction

INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def dfs(now, used, graph, cost):
    for weight, node in graph[now]:
        if node in used:
            continue
        cost[node] = cost[now] * weight
        used.add(node)
        dfs(node, used, graph, cost)


def main():
    N = int(input())

    l = []
    unit_set = set()
    for _ in range(N):
        a, b, c = input().split()
        l.append((a, int(b), c))
        unit_set.add(a)
        unit_set.add(c)

    unit_no = dict()
    unit_list = list(unit_set)
    for i, unit in enumerate(unit_list):
        unit_no[unit] = i
    graph = defaultdict(list)
    for a, b, c in l:
        a = unit_no[a]
        c = unit_no[c]
        graph[c].append((Fraction(b, 1), a))
        graph[a].append((Fraction(1, b), c))

    max_c = -INF
    ans = ()
    for i in range(len(unit_list)):
        cost = [-1] * len(unit_list)
        cost[i] = 1
        used = set()
        used.add(i)
        dfs(i, used, graph, cost)
        m = max(cost)
        if m > max_c:
            ans = (cost.index(m), m, i)
            max_c = m

    print("1{0}={1}{2}".format(unit_list[ans[0]], ans[1], unit_list[ans[2]]))


if __name__ == '__main__':
    main()