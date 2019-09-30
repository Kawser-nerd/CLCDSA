#!/usr/bin/env python3

import sys

def solve():
    D, N = map(int, input().split())
    worst_dest_time = 0
    for i in range(N):
        pos, spe = map(int, input().split())
        dest_time = (D - pos) * 1.0 / spe
        if dest_time > worst_dest_time:
            worst_dest_time = dest_time
    return D / worst_dest_time


T = int(input())
for i in range(1, T+1):
    print("Case #%d: %s" % (i, solve()))
