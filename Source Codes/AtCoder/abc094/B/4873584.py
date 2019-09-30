n, m, x = map(int, input().split())

a = list(map(int, input().split()))

import bisect

l = bisect.bisect_left(a, x)

print(min(l, m-l))