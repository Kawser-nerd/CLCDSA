import sys
from collections import Counter

# sys.stdin = open('c1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def vanish(p, details=False):
    while p:
        if details:
            print(p)
        n = len(p)
        q = [x for x in p if x != n]
        if len(q) == len(p):
            return False
        p = q[:]
    return True


def check(n):
    if n == 3:
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                for k in range(j, n + 1):
                    p = [i, j, k]
                    if vanish(p):
                        print(p)
                        # print()
                        # vanish(p, details=True)
    if n == 5:
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                for k in range(j, n + 1):
                    for l in range(k, n + 1):
                        p = [i, j, k, l]
                        if vanish(p):
                            print(p)
                            # print()
                            # vanish(p, details=True)
    if n == 5:
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                for k in range(j, n + 1):
                    for l in range(k, n + 1):
                        for m in range(l, n + 1):
                            p = [i, j, k, l, m]
                            if vanish(p):
                                print(p)
                                # print()
                                # vanish(p, details=True)


def solve_small():
    # check(3)
    # check(4)
    # check(5)
    n, m = read_int_list()
    a = read_int_list()
    p = [read_int_list() for _ in range(m)]
    c = Counter(a)
    res = []
    for x, y in p:
        c[a[x - 1]] -= 1
        a[x - 1] = y
        c[a[x - 1]] += 1
        covered = set(range(n))
        for i, ni in c.items():
            for j in range(i - ni, i):
                if j in covered:
                    covered.remove(j)
        r = len(covered)
        res.append(r)
    return '\n'.join(map(str, res))


def solve():
    n, m = read_int_list()
    a = read_int_list()
    p = [read_int_list() for _ in range(m)]
    c = Counter(a)
    covered = Counter({i: 0 for i in range(n)})
    for i, ni in c.items():
        for j in range(i - ni, i):
            if 0 <= j:
                covered[j] += 1
    r = 0
    for i, v in covered.items():
        if 0 <= i:
            if v == 0:
                r += 1
    res = []
    for x, y in p:
        x -= 1
        i = a[x] - c[a[x]]
        covered[i] -= 1
        if 0 <= i:
            if covered[i] == 0:
                r += 1
        c[a[x]] -= 1
        a[x] = y
        c[a[x]] += 1
        i = a[x] - c[a[x]]
        if 0 <= i:
            if covered[i] == 0:
                r -= 1
        covered[i] += 1
        res.append(r)
    return '\n'.join(map(str, res))


def main():
    res = solve()
    print(res)


if __name__ == '__main__':
    main()