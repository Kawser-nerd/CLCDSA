import sys

# sys.stdin = open('f1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def solve():
    X = read_int()
    K = read_int()
    r = read_int_list()
    Q = read_int()
    j = 0
    sign = -1
    s = 0
    e = X
    y = 0
    origin = 0
    out = [0] * Q
    for i in range(Q):
        t, a = read_int_list()
        while j < K and r[j] < t:
            d = r[j] - origin
            y += d * sign
            if y < 0:
                s += abs(y)
                if s > e:
                    s = e
                y = 0
            if y + e - s > X:
                diff = (y + e - s) - X
                e -= diff
                if e < s:
                    e = s
            if y > X:
                y = X
            origin = r[j]
            j += 1
            sign *= -1
        d = t - origin
        if a <= s:
            res = y
        elif a <= e:
            res = y + a - s
        else:
            res = y + e - s
        res += d * sign
        if res < 0:
            res = 0
        if res > X:
            res = X
        out[i] = res
    return out


def main():
    res = solve()
    print(*res, sep='\n')


if __name__ == '__main__':
    main()