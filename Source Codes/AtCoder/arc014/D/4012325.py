import itertools
import bisect
ALL, N, M = [int(_) for _ in input().split()]
L = [int(input()) for _ in range(N)]
XY = [[int(_) for _ in input().split()] for _ in range(M)]

diff = [0] + sorted([L[_] - L[_ - 1] - 1 for _ in range(1, N)])
cumsum = list(itertools.accumulate(diff))

for x, y in XY:
    ans = N + min(x, L[0] - 1) + min(y, ALL - L[-1])
    i = bisect.bisect_left(diff, x + y)
    ans += cumsum[i - 1] + (N - i) * (x + y)
    print(ans)