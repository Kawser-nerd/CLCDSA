# -*- coding: utf-8 -*-


def main():
    s = input()
    n = len(s)
    ans = 0

    for i in range(1, n + 1):
        cur = s[i - 1]

        if cur == 'U':
            upper = 1
        else:
            upper = 2

        ans += (n - i) * upper

        if cur == 'U':
            lower = 2
        else:
            lower = 1

        ans += (i - 1) * lower

    print(ans)


if __name__ == '__main__':
    main()