from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


# Locate the leftmost value exactly equal to x
def index_left(a: list, x):
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError


# Locate the rightmost value exactly equal to x
def index_right(a: list, x):
    i = bisect_right(a, x)
    if i and a[i - 1] == x:
        return i - 1
    raise ValueError


def main():
    N = int(input())
    r_list = []
    r_h_list = []
    r_h_dict = defaultdict(lambda: [0, 0, 0])
    for _ in range(N):
        R, H = map(int, input().split())
        H -= 1
        r_list.append(R)
        r_h_list.append((R, H))
        r_h_dict[R][H] += 1

    r_list.sort()
    for r, h in r_h_list:
        win = index_left(r_list, r)
        i = index_right(r_list, r)
        lose = N - i - 1
        draw = 0
        win += r_h_dict[r][(h + 1) % 3]
        lose += r_h_dict[r][(h - 1) % 3]
        draw += r_h_dict[r][h]
        print(win, lose, draw - 1)

if __name__ == '__main__':
    main()