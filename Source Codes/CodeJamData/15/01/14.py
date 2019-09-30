#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    _, s = input().split()
    standing = 0
    invited = 0
    for i, c in enumerate(s):
        standing += int(c)
        if standing <= i:
            invited += 1
            standing += 1
    print("Case #{}: {}".format(case, invited))

