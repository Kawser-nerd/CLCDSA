#!/usr/bin/env python3
import bisect

a = ord('a')

def solve(n, k, s):
    if n // 2 < k:
        return False

    d = {}
    t = [0] * 26
    for c in s[:k]:
        t[ord(c) - a] += 1
    u = ' '.join(list(map(str, t)))
    d[u] = 0
    for i in range(1, n - k + 1):
        t[ord(s[i - 1]) - a] -= 1
        t[ord(s[k - 1 + i]) - a] += 1
        u = ' '.join(list(map(str, t)))
        if u in d:
            if k <= i - d[u]:
                return True
        else:
            d[u] = i

    return False


def main():
    n, k = input().split()
    n = int(n)
    k = int(k)
    s = input()

    print('YES' if solve(n, k, s) else 'NO')


if __name__ == '__main__':
    main()