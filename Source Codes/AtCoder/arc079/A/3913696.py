# -*- coding: utf-8 -*-


def main():
    n, m = map(int, input().split())
    is_included_1 = set()
    is_included_n = set()

    for i in range(m):
        ai, bi = map(int, input().split())

        if ai == 1:
            is_included_1.add(bi)
        elif bi == 1:
            is_included_1.add(ai)

        if ai == n:
            is_included_n.add(bi)
        elif bi == n:
            is_included_n.add(ai)

    if len(is_included_1 & is_included_n) > 0:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


if __name__ == '__main__':
    main()