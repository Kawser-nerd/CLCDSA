from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)
INF = float("inf")
YES, Yes, yes, NO, No, no = "YES", "Yes", "yes", "NO", "No", "no"
dy4, dx4 = [0, 1, 0, -1], [1, 0, -1, 0]
dy8, dx8 = [0, -1, 0, 1, 1, -1, -1, 1], [1, 0, -1, 0, 1, 1, -1, -1]


def inside(y, x, H, W):
    return 0 <= y < H and 0 <= x < W


def ceil(a, b):
    return (a + b - 1) // b


def check(A, operations):
    c = A[:]
    for o in operations:
        if o == 1:
            A = A[1:]
        elif o == len(A):
            A = A[:len(A) - 1]
        else:
            o -= 1
            A = A[:o - 1] + [A[o - 1] + A[o + 1]] + A[o + 2:]

    if len(A) != 1:
        print(c)
        print(operations)
    assert(len(A) == 1)
    return A[0]


def solve(N, A):

    if max(A) < 0:
        ans = max(A)
        idx = A.index(ans)
        operations = []
        for i in range(N, idx + 1, -1):
            operations.append(i)
        for i in range(1, idx + 1):
            operations.append(1)
        return ans, operations

    ans = 0
    middle = []
    start, end = None, None
    for i in range(0, N, 2):
        if A[i] >= 0:
            ans += A[i]
            if start is None:
                start = i
            end = i
        else:
            if start is not None:
                middle.append(i)

    operations = []
    num = 0
    for i in range(end + 1, N):
        operations.append(N - num)
        num += 1

    for i in middle[::-1]:
        if start < i < end:
            operations.append(i + 1)
            num += 2

    for i in range(start):
        operations.append(1)
        num += 1

    for i in range((N - num) // 2):
        operations.append(2)

    return ans, operations


def main():
    N = int(input())
    A = list(map(int, input().split()))

    ans1, ope1 = solve(N, A[:])
    ans2, ope2 = solve(N - 1, A[1:])
    ope2 = [1] + ope2

    if ans1 > ans2:
        print(ans1)
        print(len(ope1))
        print(*ope1, sep="\n")
    else:
        print(ans2)
        print(len(ope2))
        print(*ope2, sep="\n")


if __name__ == '__main__':
    main()