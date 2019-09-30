# -*- coding: utf-8 -*-


def main():
    n, c = map(int, input().split())
    a = [int(input()) for _ in range(n)]
    ans = float('inf')

    for first in range(1, 11):
        for second in range(1, 11):
            if first != second:
                cost = 0

                for i in range(n):
                    if i % 2 == 0 and a[i] != first:
                        cost += c
                    elif i % 2 == 1 and a[i] != second:
                        cost += c

                ans = min(ans, cost)

    print(ans)


if __name__ == '__main__':
    main()