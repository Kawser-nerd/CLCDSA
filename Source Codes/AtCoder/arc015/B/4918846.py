# -*- coding: utf-8 -*-


def main():
    n = int(input())
    a, b, c, d, e, f = 0, 0, 0, 0, 0, 0

    for i in range(n):
        Mti, mti = map(float, input().split())
        Mti *= 10
        mti *= 10

        if Mti >= 350:
            a += 1
        elif Mti >= 300:
            b += 1
        elif Mti >= 250:
            c += 1

        if mti >= 250:
            d += 1

        if Mti >= 0 and mti < 0:
            e += 1
        elif Mti < 0:
            f += 1

    print(a, b, c, d, e, f)


if __name__ == '__main__':
    main()