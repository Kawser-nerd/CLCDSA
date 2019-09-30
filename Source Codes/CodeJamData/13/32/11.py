#!/usr/bin/env python
#
# Problem: 
# Language: Python
# Author: KirarinSnow
# Usage: python thisfile.py <input.in >output.out


for case in range(int(raw_input())):
#    int(raw_input())
    x, y = map(int, raw_input().split())

    s = ""
    s += ["EW", "WE"][x>0]*abs(x) + ["NS", "SN"][y>0]*abs(y)

    ans = s
    print "Case #%d: %s" % (case+1, ans)
