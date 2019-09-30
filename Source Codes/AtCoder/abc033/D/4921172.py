from math import atan2, pi
from bisect import bisect_left


def triangle(N: int, points: list)->tuple:
    acute, right, obtuse = 0, 0, 0

    right_m = pi / 2 - 1e-9  # ?????????
    right_p = pi / 2 + 1e-9  # ????????
    PI2 = pi * 2

    for i, (x0, y0) in enumerate(points):
        angles = [atan2(y-y0, x-x0) for x, y in (points[:i] + points[i+1:])]
        angles.sort()

        # ????????
        s = bisect_left(angles, angles[0] + right_m)
        # ????????
        t = bisect_left(angles, angles[0] + pi)
        # ???? 2? ????????
        angles += [x + PI2 for x in angles[:t] + [10]]

        for i in range(N-1):
            r = angles[i]
            # s ??????????????
            while angles[s] < r + right_m:
                s += 1
            # ???????
            while angles[s] <= r + right_p:
                s += 1
                right += 1
            # t ??????????????
            while angles[t] < r + pi:
                t += 1
            obtuse += t - s

    acute = N*(N-1)*(N-2)//6 - (right+obtuse)

    return acute, right, obtuse


if __name__ == "__main__":
    N = int(input())
    points = [tuple(int(s) for s in input().split()) for _ in range(N)]
    acute, right, obtuse = triangle(N, points)
    print(acute, right, obtuse)