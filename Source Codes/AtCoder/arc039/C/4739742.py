#!/usr/bin/env python3


def solve(k, s):
    x = 0
    y = 0
    m = {}
    m[(0, 0)] = (0, 0, 0, 0)
    for si in s:
        ox = x
        oy = y
        l, r, u, d = m[(x, y)]
        if si == 'L':
            x -= (l + 1)
            while (x, y) in m:
                nl = m[(x, y)][0] + 1
                x -= nl
            m[(ox, oy)] = (ox - x, r, u, d)
            m[(x, y)] = (0, ox - x, 0, 0)
        elif si == 'R':
            x += (r + 1)
            while (x, y) in m:
                nr = m[(x, y)][1] + 1
                x += nr
            m[(ox, oy)] = (l, x - ox, u, d)
            m[(x, y)] = (x - ox, 0, 0, 0)
        elif si == 'U':
            y += (u + 1)
            while (x, y) in m:
                nu = m[(x, y)][2] + 1
                y += nu
            m[(ox, oy)] = (l, r, y - oy, d)
            m[(x, y)] = (0, 0, 0, y - oy)
        elif si == 'D':
            y -= (d + 1)
            while (x, y) in m:
                nd = m[(x, y)][3] + 1
                y -= nd
            m[(ox, oy)] = (l, r, u, oy - y)
            m[(x, y)] = (0, 0, oy - y, 0)

    print(x, y)


def main():
    k = input()
    k = int(k)
    s = input()

    solve(k, s)


if __name__ == '__main__':
    main()