#!/usr/bin/env python3


def solve(n, s):

    ans = 0
    p = n
    for si in s:
        j = si.rfind('.', 0, p)
        if j != -1:
            ans += 1
            p = j
        else:
            p = n

    return ans


def main():
    n = input()
    n = int(n)
    s = []
    for _ in range(n):
        si = input()
        s.append(si)

    print(solve(n, s))


if __name__ == '__main__':
    main()