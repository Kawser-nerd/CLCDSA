#!/usr/bin/env python3
import bisect

X_MAX = 10 ** 20


def calc(k, n, a, d, y):
    r = k
    for i in range(n):
        if a[i] < y:
            r -= (y - a[i] + d[i] - 1) // d[i]
            if r < 0:
                return r
    return r

def solve(k, n, a, d):

    ok = 1
    ng = X_MAX
    while ok + 1 < ng:
        mid = (ok + ng) // 2
        if calc(k, n, a, d, mid) < 0:
            ng = mid
        else:
            ok = mid

    ans = 0
    r = k
    lst = []
    for i in range(n):
        if a[i] < ok:
            x = (ok - a[i] + d[i] - 1) // d[i]
            ans += a[i] * x + d[i] * x * (x - 1) // 2
            r -= x
            lst.append((a[i] + d[i] * x, i))
        else:
            lst.append((a[i], i))

    lst.sort()
    while 0 < r:
        y, i = lst.pop(0)
        ans += y
        r -= 1
        v = (y + d[i], i)
        lst.insert(bisect.bisect_left(lst, v), v)

    return ans


def main():
    k = input()
    k = int(k)
    n = input()
    n = int(n)
    a = []
    d = []
    for _ in range(n):
        ai, di = input().split()
        ai = int(ai)
        di = int(di)
        a.append(ai)
        d.append(di)

    print(solve(k, n, a, d))


if __name__ == '__main__':
    main()