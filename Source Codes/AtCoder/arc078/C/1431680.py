import sys


# sys.stdin = open('e1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


debug = False
N = 5600070
if debug:
    print()
    print('N:', N)
    print()


def ask(n):
    if debug:
        res = (n <= N and str(n) <= str(N)) or (n >= N and str(n) >= str(N))
        print('?', n, '\t', res)
        return res
    print('?', n, flush=True)
    return input() in ['y', 'Y']


def solve():
    if ask(10 ** 9):
        # N is a power of 10
        for k in range(10):
            if ask(2 * 10 ** k):
                return 10 ** k

    # Find the number of digits of N
    l = 1
    while ask(10 ** l):
        l += 1

    d = [9] * l
    for p in range(l):

        a = 0
        if p == 0:
            a = 1
        b = 9

        d[p] = a
        n = int(''.join(map(str, d)))
        if ask(10 * n):
            continue

        while b - a > 1:
            m = (a + b) // 2
            d[p] = m
            n = int(''.join(map(str, d)))
            if ask(10 * n):
                b = m
            else:
                a = m
        d[p] = b
    n = int(''.join(map(str, d)))
    return n


def main():
    res = solve()
    print('!', res, flush=True)


if __name__ == '__main__':
    main()