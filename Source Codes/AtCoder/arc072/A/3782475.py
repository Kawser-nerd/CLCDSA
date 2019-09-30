import sys

sys.setrecursionlimit(10 ** 6)
_ = int(input())
A = list(map(int, input().split()))


def solve(i, s, k, sign):
    if i >= len(A):
        return k

    if sign * (s + A[i]) > 0:
        return solve(i + 1, s + A[i], k, sign * -1)
    else:
        return solve(i + 1, sign, k + abs(s + A[i]) + 1, sign * -1)


print(min(solve(0, 0, 0, 1), solve(0, 0, 0, -1)))