# coding:utf-8

import sys


input = sys.stdin.readline


def inpl(): return list(map(int, input().split()))


def solve():
    H, W, h, w = inpl()

    if H % h == 0 and W % w == 0:
        print('No')
        return -1

    ans = [[1000] * W for _ in range(H)]
    cnt = 0
    for i in range(h - 1, H, h):
        for j in range(w - 1, W, w):
            ans[i][j] = -(h * w - 1) * 1000 - 1
            cnt += 1

    print('Yes')
    for row in ans:
        print(' '.join(map(str, row)))

    return 0


solve()