#!/usr/bin/env python3


class UnionFindX():
    def __init__(self, size):
        self.table = [-1] * size
        self.check = [True] * size
        self.parity = [0] * size

    def find(self, x):
        p = 0
        while 0 <= self.table[x]:
            p += self.parity[x]
            x = self.table[x]
        c = self.check[x]
        p %= 2
        return x, c, p

    def unite(self, x, y, p):
        rx, cx, px = self.find(x)
        ry, cy, py = self.find(y)
        r = rx
        if rx != ry:
            dx = -self.table[rx]
            dy = -self.table[ry]
            if dx != dy:
                if dx < dy:
                    self.table[rx] = ry
                    if cx and cy:
                        self.parity[rx] = (p + px + py) % 2
                    else:
                        self.check[ry] = False
                    r = ry
                else:
                    self.table[ry] = rx
                    if cx and cy:
                        self.parity[ry] = (p + px + py) % 2
                    else:
                        self.check[rx] = False
            else:
                self.table[rx] -= 1
                self.table[ry] = rx
                if cx and cy:
                    self.parity[ry] = (p + px + py) % 2
                else:
                    self.check[rx] = False
        else:
            if (p + px + py) % 2:
                self.check[rx] = False

        return r


def solve(n, q, qry):

    uf = UnionFindX(n + 1)
    for qi in qry:
        w, x, y, z = qi
        if w == 1:
            uf.unite(x, y, z)
        else:
            rx, cx, px = uf.find(x)
            ry, cy, py = uf.find(y)
            if rx == ry:
                if cx:
                    if (px + py) % 2:
                        print('NO')
                    else:
                        print('YES')
                else:
                    print('YES')
            else:
                print('NO')



def main():
    n, q = input().split()
    n = int(n)
    q = int(q)
    qry = []
    for _ in range(q):
        w, x, y, z = input().split()
        w = int(w)
        x = int(x)
        y = int(y)
        z = int(z)
        qry.append((w, x, y, z))

    solve(n, q, qry)


if __name__ == '__main__':
    main()