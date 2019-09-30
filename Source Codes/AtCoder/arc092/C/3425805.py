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
    ans1 = 0
    del1 = []
    ok1 = False
    start1, end1 = None, None
    for i in range(0, N, 2):
        if A[i] >= 0:
            ans1 += A[i]
            ok1 = True
            if start1 is None:
                start1 = i
            end1 = i
        else:
            if ok1:
                del1.append(i)

    ans2 = 0
    del2 = [1]
    ok2 = False
    start2 = None
    end2 = None
    for i in range(1, N, 2):
        if A[i] >= 0:
            ans2 += A[i]
            ok2 = True
            if start2 is None:
                start2 = i
            end2 = i
        else:
            if ok2:
                del2.append(i)

    ans, dele, start, end = None, None, None, None
    if ok1 and ok2:
        if ans1 > ans2:
            ans, dele, start, end = ans1, del1, start1, end1
        else:
            ans, dele, start, end = ans2, del2, start2, end2
    elif ok1:
        ans, dele, start, end = ans1, del1, start1, end1
    elif ok2:
        ans, dele, start, end = ans2, del2, start2, end2

    if not ok1 and not ok2:
        ans = max(A)
        idx = A.index(ans)
        a = []
        for i in range(N, idx + 1, -1):
            a.append(i)
        for i in range(1, idx + 1):
            a.append(1)
        return ans, a

    else:
        a = []
        num = 0
        for i in range(end + 1, N):
            a.append(N - num)
            num += 1

        for i in dele[::-1]:
            if start < i < end:
                a.append(i + 1)
                num += 2

        for i in range(start):
            a.append(1)
            num += 1

        for i in range((N - num) // 2) :
            a.append(2)

        return ans, a


def main():
    N = int(input())
    A = list(map(int, input().split()))

    ans, ope = solve(N, A[:])
    print(ans)
    print(len(ope))
    print(*ope, sep="\n")

    
if __name__ == '__main__':
    main()