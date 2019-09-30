import sys
import socket

if socket.gethostname() in ['N551J', 'F551C']:
    test_case = 'c1.in'
    sys.stdin = open(test_case)


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def solve():
    n = read_int()
    rows = [read_int_list() for i in range(n)]
    a, b = map(list, zip(*rows))
    res = sum(a)
    res = min(res, sum(b))
    all_values = [(a[i], i, 0) for i in range(n)]
    all_values.extend([(b[i], i, 1) for i in range(n)])
    all_values.sort()
    index_of_value = {v: i for i, v in enumerate(all_values)}
    first_values = [
        set(all_values[:n - 2]),
        set(all_values[:n - 1]),
        set(all_values[:n]),
    ]

    s = [sum([t[0] for t in v]) for v in first_values]
    for i in range(n):
        rest = []
        k = 0
        last = n - 2
        indices = sorted([(index_of_value[(a[i], i, 0)], a[i]),
                          (index_of_value[(b[i], i, 1)], b[i])])

        for index, value in indices:
            if index < last:
                last += 1
                k += 1
            else:
                rest.append(value)
        t = s[k] + sum(rest)
        res = min(res, t)
    return res


def main():
    res = solve()
    print(res)


if __name__ == '__main__':
    main()