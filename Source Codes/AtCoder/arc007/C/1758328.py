import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def main():
    s = input()
    n = len(s)
    l = []
    for i in range(n):
        l.append(s)
        s = s[1:] + s[0]

    ans = INF
    for b in range(2 ** n):
        use = []
        for i in range(n):
            if b & 1 << i:
                use.append(l[i])

        for i in range(n):
            ok = False
            for j in range(len(use)):
                ok |= use[j][i] == "o"
            if not ok:
                break
        else:
            ans = min(ans, len(use))
    print(ans)


if __name__ == '__main__':
    main()