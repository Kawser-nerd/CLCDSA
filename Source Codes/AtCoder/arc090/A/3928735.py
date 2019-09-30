# -*- coding: utf-8 -*-


def main():
    n = int(input())
    a = [list(map(int, input().split())) for _ in range(2)]
    ans = 0

    for i in range(n):
        ans = max(ans, sum(a[0][:i + 1]) + sum(a[1][i:]))

    print(ans)


if __name__ == '__main__':
    main()