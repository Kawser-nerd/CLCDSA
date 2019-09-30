import sys
import collections
import math
from collections import Counter
from collections import deque


H, W = [int(x) for x in input().split()]

ans = 10**10

# ???? ?????


def calc1(H, W):
    if H % 3 == 0:
        return 0
    else:
        return W


def calc2(H, W):
    ret = 10**10
    for w in range(1, W):
        s1 = w * H
        h = H // 2
        s2 = h * (W - w)
        s3 = (H - h) * (W - w)
        maxS = max(s1, s2, s3)
        minS = min(s1, s2, s3)
        ret = min(abs(maxS - minS), ret)
    return ret


s1 = calc1(H, W)
s2 = calc1(W, H)
s3 = calc2(H, W)
s4 = calc2(W, H)

print(min(s1, s2, s3, s4))


sys.exit(0)