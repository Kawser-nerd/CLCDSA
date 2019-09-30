#!/usr/bin/env python
import itertools
n = int(input())
nums = []
pre_nums = ['3','5','7']

for i in range(3,10):
    for ids in itertools.product(pre_nums, repeat=i):
        if '3' in ids and '5' in ids and '7' in ids:
            nums.append(int(''.join(ids)))
for i,num in enumerate(nums):
    if n < num:
        print(i)
        break
else:
    print(len(nums))