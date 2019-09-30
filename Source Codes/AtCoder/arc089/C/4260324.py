#!/usr/bin/env python3


def solve(x_max, y_max, d):

    c_table = [[-1] * 100 for _ in range(100)]

    for a in range(100):
        c_table_a = c_table[a]
        for x in range(x_max):
            ax = a * (x + 1)
            dx = d[x]
            for b in range(100):
                c = -1
                for y in range(y_max):
                    c = max(c, dx[y] - ax - b * (y + 1))
                c_table_a[b] = max(c_table_a[b], c)

    ab_max = 0
    c_set = {}
    for x in range(x_max):
        dx = d[x]
        for y in range(y_max):
            dxy = d[x][y]
            f = False
            for a in range(100):
                c_table_a = c_table[a]
                ax = a * (x + 1)
                for b in range(100):
                    if dxy == ax + b * (y + 1) + c_table_a[b]:
                        ab_max = max(ab_max, a, b)
                        c_set[(a, b)] = c_table_a[b]
                        f = True
                        break
                if f: break
            if not f:
                print('Impossible')
                return


    print('Possible')
    print('{} {}'.format((ab_max + 1) * 2, ab_max * 2 + len(c_set)))
    for i in range(ab_max):
        print('{} {} X'.format(i + 1, i + 2))
    for i in range(ab_max):
        print('{} {} Y'.format(ab_max + i + 3, ab_max + i + 2))
    for k, c in c_set.items():
        print('{} {} {}'.format(k[0] + 1, k[1] + ab_max + 2, c))
    print('{} {}'.format(1, ab_max + 2))


def main():
    A, B = input().split()
    A = int(A)
    B = int(B)
    d = [list(map(int, input().split())) for _ in range(A)]

    solve(A, B, d)


if __name__ == '__main__':
    main()