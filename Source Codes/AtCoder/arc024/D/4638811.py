#!/usr/bin/env python3


def divide(pt, d, r):

    if len(pt) == 1:
        return
    if len(pt) == 2:
        v0 = pt[0]
        v1 = pt[1]
        if v0[0] != v1[0] and v0[1] != v1[1]:
            r.add((v0[0], v1[1]))
        return

    pt.sort(key = lambda x: x[d])
    i = len(pt) // 2
    if d == 0:
        pv0 = pt[i][0]
        for v in pt:
            r.add((pv0, v[1]))
    else:
        pv1 = pt[i][1]
        for v in pt:
            r.add((v[0], pv1))
    pt0 = pt[:i]
    pt1 = pt[i + 1:]
    nd = 1 - d
    divide(pt0, nd, r)
    divide(pt1, nd, r)


def solve(n, pt):

    org = set()
    r = set()
    for v in pt:
        org.add(v)

    divide(pt, 0, r)

    for v in org:
        if v in r:
            r.remove(v)

    print(len(r))
    for v in r:
        x, y = v
        print('{} {}'.format(x, y))


def main():
    n = input()
    n = int(n)
    pt = []
    for _ in range(n):
        x, y = input().split()
        x = int(x)
        y = int(y)
        pt.append((x, y))

    solve(n, pt)


if __name__ == '__main__':
    main()