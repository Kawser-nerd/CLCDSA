#!/usr/bin/env python
import itertools
from operator import mul
from functools import reduce


N = int(input())
F = 1
for i in range(1,N+1):
    F = F*i

pns = []
for n in range(2, N+1):
    for pn in pns:
        if n % pn == 0:
            break
    else:
        pns.append(n)
c = 0
for num in pns:
    if F % num**74 == 0:
        c += 1
for nums in itertools.combinations(pns, 2):
    y1 = nums[0]**14 * nums[1]**4
    y2 = nums[1]**14 * nums[0]**4
    z1 = nums[0]**24 * nums[1]**2
    z2 = nums[1]**24 * nums[0]**2
    if F % y1 == 0:
        c += 1
    if F % y2 == 0:
        c += 1
    if F % z1 == 0:
        c += 1
    if F % z2 == 0:
        c += 1
for nums in itertools.combinations(pns, 3):
    for num in nums:
        num_except = [n for n in nums if n != num]
        x = num**2 * (num_except[0]*num_except[1])**4
        if F % x == 0:
            c += 1
print(c)