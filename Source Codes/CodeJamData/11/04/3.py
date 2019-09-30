#!/usr/bin/env python

for c in range(int(raw_input())):
    n = int(raw_input())
    x = [int(y) for y in raw_input().split()]
    result = sum([0 if x[i] == i+1 else 1 for i in range(n)])
    print 'Case #{}: {:.6f}'.format(c+1, result)
