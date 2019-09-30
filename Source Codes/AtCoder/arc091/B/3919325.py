# -*- coding: utf-8 -*-


def main():
    n, k = map(int, input().split())
    ans = 0

    if k == 0:
        print(n ** 2)
        exit()

    for i in range(k + 1, n + 1):
        p, q = divmod(n, i)
        ans += p * (i - k)
        ans += max(q - k + 1, 0)

    print(ans)


if __name__ == '__main__':
    main()