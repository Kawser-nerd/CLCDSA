#!/usr/bin/env python3

def main():
    N = int(input())
    p = list(map(int, input().split()))

    r = 0
    i = 0
    while i < N:
        if p[i] == i + 1:
            r += 1
            i += 1
        i += 1

    print(r)


if __name__ == '__main__':
    main()