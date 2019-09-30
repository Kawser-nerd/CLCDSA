import numpy as np
import sys

N, K = map(int, input().split())
wp = np.array([list(map(int, sys.stdin.readline().split())) for _ in range(N)])
w = wp[:, 0]
p = wp[:, 1]

amax = np.max(p)
amin = np.min(p)

a = (amax + amin) / 2

while amax - amin > 0.0000000003:
    x = w * (p - a)
    if np.sum(np.sort(x)[-K:]) > 0:
        amin = a
        a = (amax + a) / 2
    else:
        amax = a
        a = (amin + a) / 2

print(round(amax, 9))