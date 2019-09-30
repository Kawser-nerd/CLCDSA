#!/usr/bin/env python3

def main():
    N = int(input())
    S1 = input()
    S2 = input()

    m = 10 ** 9 + 7
    v = (S1[0] == S2[0])
    r, i = 0, 0
    if v:
        r = 3
        i = 1
    else:
        r = 6
        i = 2

    while i < N:
        if S1[i] == S2[i]:
            if v:
                r *= 2
                r %= m
            v = True
            i += 1
        else:
            if v:
                r *= 2
                r %= m
            else:
                r *= 3
                r %= m
            v = False
            i += 2


    print(r)


if __name__ == '__main__':
    main()