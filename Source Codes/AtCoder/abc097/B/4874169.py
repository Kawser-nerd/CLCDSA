n = int(input())

x = []

for i in range(1, 33):
  x = x +[i ** j for j in range(2, 10)]

x.sort()

import bisect

b = bisect.bisect_right(x, n)

print(x[b-1])