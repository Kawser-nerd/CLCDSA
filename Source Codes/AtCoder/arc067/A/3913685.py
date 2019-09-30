# -*- coding: utf-8 -*-


def solve(m: int):
    from math import sqrt

    ans = dict()
    remain = m

    for j in range(2, int(sqrt(m)) + 1):
        if remain % j == 0:
            count = 0

            while remain % j == 0:
                count += 1
                remain //= j

            ans[j] = count

    if remain != 1:
        ans[remain] = 1

    return ans


def main():
    n = int(input())
    d = dict()
    mod = 10 ** 9 + 7
    ans = 1

    for i in range(2, n + 1):
        new = solve(i)

        for key, value in new.items():
            if key not in d.keys():
                d[key] = value
            else:
                d[key] += value

    for di in d.values():
        ans *= (di + 1)
        ans %= mod

    print(ans)


if __name__ == '__main__':
    main()