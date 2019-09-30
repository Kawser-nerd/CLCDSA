#!/usr/bin/env python3


def make_result(n, a, b):
    result = []
    tail = []
    if n < a * b:
        if a <= b:
            k = (a * b - n + b - 2)//(b - 1) - 1
            tail = [n - i for i in range(k - 1, -1, -1)]
            n -= k
            a -= k
            k = n - (a - 1) * b
            tail = [n - i for i in range(k)] + tail
            n -= k
            a -= 1
        else:
            k = (a * b - n + a - 2)//(a - 1) - 1
            result = [n - i for i in range(k)]
            n -= k
            b -= k
            k = n - a * (b - 1)
            result += [n - i for i in range(k - 1, -1, -1)]
            n -= k
            b -= 1

    for i in range(b):
        for j in range(a):
            result.append(n - a * (i + 1) + j + 1)

    return result + tail


def solve(n, a, b):
    if n < a + b - 1:
        return '-1'
    if a * b < n:
        return '-1'

    return ' '.join(map(str, make_result(n, a, b)))


def main():
    n, a, b = input().split()
    n = int(n)
    a = int(a)
    b = int(b)

    print(solve(n, a, b))


if __name__ == '__main__':
    main()