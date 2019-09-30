# -*- coding: utf-8 -*-
s = input()+"T"
n = len(s)
x,y = map(int, input().split())

fcnt = 0
tcnt = 0
xd = set()
yd = set([0])
for i in range(n):
    if s[i]=="F":
        fcnt += 1
        continue

    if tcnt==0:
        xd.add(fcnt)
    elif tcnt%2==0:
        # x????
        tmp = set()
        for xx in xd:
            tmp.add(xx-fcnt)
            tmp.add(xx+fcnt)
        xd = tmp
    else:
        # y????
        tmp = set()
        for yy in yd:
            tmp.add(yy-fcnt)
            tmp.add(yy+fcnt)
        yd = tmp
    tcnt += 1
    fcnt = 0

if x in xd and y in yd:
    print("Yes")
else:
    print("No")