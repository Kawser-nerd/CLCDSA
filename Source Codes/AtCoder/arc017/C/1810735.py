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
    N, X = map(int, input().split())

    w_list = [int(input()) for _ in range(N)]

    w_list1, w_list2 = w_list[:N // 2], w_list[N // 2:]

    # 2 ^ n??????????
    n = len(w_list1)
    s = []
    for b in range(2 ** n):
        total = 0
        for i in range(n):
            if b & 1 << i:
                total += w_list1[i]
        s.append(total)

    n = len(w_list2)
    d = defaultdict(int)
    for b in range(2 ** n):
        total = 0
        for i in range(n):
            if b & 1 << i:
                total += w_list2[i]
        d[total] += 1

    ans = 0
    for a in s:
        if a > X:
            continue
        ans += d[X - a]
    print(ans)


if __name__ == '__main__':
    main()