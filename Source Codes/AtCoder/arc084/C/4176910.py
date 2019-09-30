#!/usr/bin/env python3

import math

def main():
    [K, N] = list(map(int, input().split()))

    r = []
    if K == 1:
        r = [1] * ((N + 1) // 2)
    elif K % 2 == 0:
        r = [K // 2]
        r += [K] * (N - 1)
    else:
        t = N // 2
        x = int(math.log(N * (K - 1) + 1, K) - 1)
        while t < ((K ** (x + 1) - 1) / (K - 1) + x) // 2:
            x -= 1
        x += 1
        r = [(K + 1) // 2] * (N - x)
        r += [0] * x
        t = ((K ** (x + 1) - 1) / (K - 1) + x) // 2 - t
        for i in range(x, 0, -1):
            r[N - i] = 1
            t -= 1
            for j in range(K - 1):
                if t == 0:
                    break
                if K ** i - 1 <= t * (K - 1):
                    r[N - i] += 1
                    t -= (K ** i - 1) // (K - 1)
            if t == 0:
                break

        for i in range(len(r) - 1, -1, -1):
            if r[i] == 0:
                r.pop()
            else:
                break


    print(' '.join(list(map(str, r))))


if __name__ == '__main__':
    main()