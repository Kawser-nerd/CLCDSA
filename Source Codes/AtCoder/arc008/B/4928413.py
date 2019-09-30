# -*- coding: utf-8 -*-


def main():
    from collections import Counter
    from math import ceil

    n, m = map(int, input().split())
    name = input()
    kit = input()
    ans = 0

    for name_i in name:
        if name_i not in kit:
            print(-1)
            exit()

    kit_count = Counter(kit)

    for key, value in Counter(name).items():
        ans = max(ans, ceil(value / kit_count[key]))

    print(ans)


if __name__ == '__main__':
    main()