# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def solve(n, x):
    if x < n - x:
        x = n - x
    w = n - x
    t = (w - (x % w)) % w
    res = (x + w - 1) // w * 3 * w - t * 3
    if t != 0:
        res += solve(w, w - t)
    return res


def main():
    n, x = rli()
    print(solve(n, x))


if __name__ == '__main__':
    main()