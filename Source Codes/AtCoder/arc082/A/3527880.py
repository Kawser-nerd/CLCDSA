N = int(input())
A = [int(x) for x in input().split()]

import collections

cnt = collections.Counter(A)

minval = min(A)
maxval = max(A)

ret = 0
for i in range(minval, maxval+1):
    s = cnt[i - 1] + cnt[i] + cnt[i + 1]
    ret = max([ret, s])

print(ret)