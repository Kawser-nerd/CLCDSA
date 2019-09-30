#!/usr/bin/env python3

def main():
    N = int(input())
    a = list(map(int, input().split()))

    a.sort()
    r = 0
    i, j = 0, 0
    while i < N:
        while j < N:
            if a[j] - a[i] <= 2:
                j += 1
            else:
                break
        r = max(r, j - i)
        if j == N:
            break
        i += 1

    print(r)


if __name__ == '__main__':
    main()