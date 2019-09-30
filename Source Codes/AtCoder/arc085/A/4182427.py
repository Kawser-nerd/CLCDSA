#!/usr/bin/env python3

def solve(n, m):
    return (100 * n + 1800 * m) * (2 ** m)

def main():
    n, m = input().split()
    n = int(n)
    m = int(m)

    print(solve(n, m))


if __name__ == '__main__':
    main()