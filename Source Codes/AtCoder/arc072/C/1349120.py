#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math

N,D = map(int, sys.stdin.readline().rstrip().split())
ds = list(map(int, sys.stdin.readline().rstrip().split()))
Q, = map(int, sys.stdin.readline().rstrip().split())
qs = list(map(int, sys.stdin.readline().rstrip().split()))


targets = [1]
for d in reversed(ds):
    if(d//2 < targets[-1]):
        targets.append(targets[-1] + d)
    else:
        targets.append(targets[-1])
targets.reverse()

current = D
can_avoids = []
for i in range(N):
    d = ds[i]
    target = targets[i+1]
    #print("current:", current)
    can_avoids.append(current >= target)
    if d//2 < current:
        current -= d
        current = max(-current, current)

#print(targets)
#print(can_avoids)

for q in qs:
    if (can_avoids[q-1]):
        print("YES")
    else:
        print("NO")


exit(0)