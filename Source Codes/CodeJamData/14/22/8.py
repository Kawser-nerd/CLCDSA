import sys
from itertools import zip_longest as zip

T = int(sys.stdin.readline().strip())

for t in range(T):
    A, B, K = tuple(int(i) for i in sys.stdin.readline().strip().split())

    cnt = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                cnt += 1

    print("Case #%d: %d" % (t+1, cnt))
