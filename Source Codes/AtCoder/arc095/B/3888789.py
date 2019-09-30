# -*- coding: utf-8 -*-


def main():

    n = input()
    a = sorted(list(map(int, input().split())))
    ai = max(a)
    a.remove(ai)
    aj = float('inf')
    tmp = float('inf')

    for aa in a:
        diff = abs(ai / 2 - aa)

        if diff < tmp:
            tmp = diff
            aj = aa

    print(ai, aj)


if __name__ == '__main__':
    main()