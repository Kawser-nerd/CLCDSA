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


def lis(A):
    N = len(A)
    LIS = []

    for i in range(N):
        index = bisect_left(LIS, A[i])
        if index >= len(LIS):
            LIS.append(A[i])
        else:
            LIS[index] = A[i]

    return len(LIS)


def func(A):
    return lis(A), lis([-1 * a for a in A])


def solve(N, A, B):
    ans = []
    now = 1
    num = 0
    while now <= N:
        for i in range(min(N, now + B - 1), now - 1, -1):
            ans.append(i)
        now += B
        num += 1
        rest = N - now + 1
        if 1 + rest - B < A - num:
            break

    for _ in range(A - num - 1):
        ans.append(now)
        now += 1
        num += 1
        if now == N:
            break

    use = False
    for i in range(N, now - 1, -1):
        ans.append(i)
        use = True

    if num + use != A:
        return [-1]

    return ans


def check(N, A, B):
    for p in permutations(range(1, N + 1)):
        if (A, B) == func(list(p)):
            return list(p)
    return [-1]


def main():
    N, A, B = map(int, input().split())
    ans = solve(N, A, B)
    print(*ans)


if __name__ == '__main__':
    main()