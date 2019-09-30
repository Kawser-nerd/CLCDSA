#!/usr/bin/env python3


def main():

    N = int(input())
    points = []
    for i in range(N):
        points.append(list(map(int, input().split())))

    x = [p[0] for p in points]
    y = [p[1] for p in points]

    M = 998244353

    c = 1 + N + N * (N - 1) // 2
    for i in range(N):
        xi = x[i]
        yi = y[i]
        dx = [xj - xi for xj in x]
        dy = [yj - yi for yj in y]

        for j in range(i + 1, N):
            xj = dx[j]
            yj = dy[j]
            cc = 1
            for k in range(j + 1, N):
                if xj * dy[k] - dx[k] * yj == 0:
                    cc *= 2
                    cc %= M
            c += cc - 1

    r = 1
    for i in range(N):
        r *= 2
        r %= M

    r -= c
    r %= M

    print(r)


if __name__ == '__main__':
    main()