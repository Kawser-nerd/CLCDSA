#!/usr/bin/env python3

def main():
    n, z, w = input().split()
    n = int(n)
    w = int(w)
    a = list(map(int, input().split()))
    a = [w] + a

    sx = s_min = s_max = abs(a[n] - a[n - 1])
    for i in range(n - 1, 0, -1):
        sx = max(s_max, abs(a[n] - a[i - 1]))
        sy = min(s_min, abs(a[n] - a[i - 1]))
        s_max = max(s_max, sy)
        s_min = min(s_min, sx)

    print(sx)


if __name__ == '__main__':
    main()