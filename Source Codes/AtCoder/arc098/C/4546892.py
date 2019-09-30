#!/usr/bin/env python3


def solve(n, k, q, a):

    sorted_pairs = [(ai, i) for i, ai in enumerate(a)]
    sorted_pairs.sort()


    ans = 10 ** 10
    segments = [(0, n)]
    ly = 0
    for i in range(n - q + 1):
        y, _ = sorted_pairs[i]
        if y == ly:
            continue
        ly = y
        b = []
        for left, right in segments:
            if k <= right - left:
                c = a[left:right].copy()
                c.sort()
                b += c[:right - left - k + 1]
        if q <= len(b):
            b.sort()
            x = b[q - 1]
            ans = min(ans, x - y)
        i_end = n - q + 1
        for i2 in range(i + 1, n - q + 1):
            if sorted_pairs[i2][0] != y:
                i_end = i2
                break
        for i2 in range(i, i_end):
            _, j = sorted_pairs[i2]
            for h, seg in enumerate(segments):
                left, right = seg
                if left <= j and j < right:
                    segments.pop(h)
                    segments.append((left, j))
                    segments.append((j + 1, right))
                    break

    return ans


def main():
    n, k, q = input().split()
    n = int(n)
    k = int(k)
    q = int(q)
    a = list(map(int, input().split()))

    print(solve(n, k, q, a))


if __name__ == '__main__':
    main()