#!/usr/bin/env python3
H, W, h, w = map(int, input().split())
if W % w == 0 and H % h == 0:
    print('No')
else:
    swapped = False
    if W % w == 0:
        H, W, h, w, swapped = W, H, w, h, True
    a = [ [ 0 for _ in range(W) ] for _ in range(H) ]
    for y in range(H):
        for x in range(0, W, w):
            a[y][x] = W
        for x in range(w - 1, W, w):
            a[y][x] = - W - 1
    if swapped:
        H, W, h, w = W, H, w, h
        b = a
        a = [ [ 0 for _ in range(W) ] for _ in range(H) ]
        for y in range(H):
            for x in range(W):
                a[y][x] = b[x][y]
    print('Yes')
    for y in range(H):
        print(*a[y])