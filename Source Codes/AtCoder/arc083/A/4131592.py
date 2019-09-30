#!/usr/bin/env python3

def main():
    [A, B, C, D, E, F] = list(map(int, input().split()))

    A100 = A * 100
    B100 = B * 100


    d_max = 0
    d_w = A100
    d_s = 0

    i2_max = F // B100 + 1
    for i2 in range(i2_max):
        w2 = B100 * i2
        i1_max = (F - w2) // A100 + 1
        for i1 in range(i1_max):
            w = w2 + A100 * i1
            if w == 0:
                continue
            if F <= w:
                break
            target = (w // 100) * E
            if F - w < target:
                target = F - w
            if target / (w + target) < d_max:
                continue
            q = target // (C * D)
            r = target % (C * D)
            r_max = 0
            for i3 in range(D + 1):
                x3 = C * i3
                if r < x3:
                    break
                if x3 == r:
                    r_max = r
                    break
                for i4 in range(C + 1):
                    x = x3 + D * i4
                    if r < x:
                        break
                    if x == r:
                        r_max = r
                        break
                    r_max = max(r_max, x)
                if r_max == r:
                    break
            s = C * D * q + r_max
            d = s / (w + s)
            if d_max < d:
                d_max = d
                d_w = w
                d_s = s

    print('{} {}'.format(d_w + d_s, d_s))


if __name__ == '__main__':
    main()