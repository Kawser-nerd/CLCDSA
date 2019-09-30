from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")

def can_win(i, N, A, B):
    if N == 0:
        return False
    m = A if i % 2 == 0 else B
    for j in range(1, m + 1):
        if N - j >= 0:
            if not can_win(i + 1, N - j, A, B):
                return True
    return False


def main():
    N = int(input())
    A, B = map(int, input().split())
    if N <= A:
        print("Takahashi")
    elif A == B:
        print("Takahashi" if N % (A + 1) != 0 else "Aoki")
    else:
        print("Takahashi" if A > B else "Aoki")


if __name__ == '__main__':
    main()