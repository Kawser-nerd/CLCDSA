import sys

# sys.stdin = open('c1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


H, W, h, w = read_int_list()


def solve(H, W, h, w):
    if H % h == 0 and W % w == 0:
        return False, None
    a = [[0] * W for _ in range(H)]
    m = 10 ** 9 - 1
    M = m + 1
    for i in range(0, H, h):
        for j in range(0, W, w):
            a[i][j] = m
    for i in range(h - 1, H, h):
        for j in range(w - 1, W, w):
            a[i][j] = -M
    return True, a


possible, res = solve(H, W, h, w)
if possible:
    print('Yes')
    for row in res:
        print(' '.join(map(str, row)))
else:
    print('No')