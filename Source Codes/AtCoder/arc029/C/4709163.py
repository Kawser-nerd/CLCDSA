#!/usr/bin/env python3


class UnionFind():
    def __init__(self, size):
        self.table = [-1] * size

    def find(self, x):
        while 0 <= self.table[x]:
            x = self.table[x]
        return x

    def unite(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        r = rx
        if rx != ry:
            dx = -self.table[rx]
            dy = -self.table[ry]
            if dx != dy:
                if dx < dy:
                    self.table[rx] = ry
                    r = ry
                else:
                    self.table[ry] = rx
            else:
                self.table[rx] -= 1
                self.table[ry] = rx
        return r


def solve(n, m, c, e):

    e.sort()
    d = c.copy()
    uf = UnionFind(n)
    ans = sum(c)

    for ei in e:
        r, a, b = ei
        ga = uf.find(a)
        gb = uf.find(b)
        if ga != gb:
            da = d[ga]
            db = d[gb]
            if r < max(da, db):
                ans += r - max(da, db)
                nd = min(da, db)
                ng = uf.unite(a, b)
                d[ng] = nd

    return ans


def main():
    n, m = input().split()
    n = int(n)
    m = int(m)
    c = []
    for _ in range(n):
        ci = input()
        ci = int(ci)
        c.append(ci)
    e = []
    for _ in range(m):
        a, b, r = input().split()
        a = int(a) - 1
        b = int(b) - 1
        r = int(r)
        e.append((r, a, b))

    print(solve(n, m, c, e))


if __name__ == '__main__':
    main()