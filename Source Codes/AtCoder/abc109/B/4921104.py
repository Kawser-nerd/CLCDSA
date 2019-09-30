# -*- coding: utf-8 -*-

n = int(input())
a = [input() for i in range(n)]
count = 0

for i in range(n - 1):
    if a[i][-1] != a[i+1][0]:
        count += 1

import collections
b = collections.Counter(a)

if b.most_common(1)[0][1] >= 2:
    count += 1

if count == 0:
    print('Yes')
else:
    print('No')