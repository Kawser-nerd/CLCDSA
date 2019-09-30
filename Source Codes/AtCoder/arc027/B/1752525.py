import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def main():
    N = int(input())
    s1 = list(input())
    s2 = list(input())

    change = True
    while change:
        change = False
        for c1, c2 in zip(s1, s2):
            if c1 != c2 and c1.isalpha() and c2.isalpha():
                change = True
                for i in range(N):
                    if s1[i] == c2:
                        s1[i] = c1
                    if s2[i] == c2:
                        s2[i] = c1

    a_n = {}
    for c1, c2 in zip(s1, s2):
        if c1.isnumeric():
            a_n[c2] = c1
        if c2.isnumeric():
            a_n[c1] = c2
    for i in range(N):
        s1[i] = a_n.get(s1[i], s1[i])
        s2[i] = a_n.get(s2[i], s2[i])

    assert s1 == s2
    s = set()
    ans = 1
    for i, c in enumerate(s1):
        if c.isalpha() and c not in s:
            s.add(c)
            ans *= 9 if i == 0 else 10
    print(ans)


if __name__ == '__main__':
    main()