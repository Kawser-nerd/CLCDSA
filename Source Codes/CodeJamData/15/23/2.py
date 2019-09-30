#!/usr/bin/env python3

# Google Code Jam Round 1B 2015
# Problem C. Hiking Deer
# Solution in Python
# By Smithers

for x in range(1, int(input()) + 1):
    N = int(input())
    
    # Start pos, time per lap, first crosses zero in minutes / 360.
    hikers = []
    for i in range(N):
        D, H, M = map(int, input().split())
        for j in range(M, M+H):
            hikers.append((D, j, (360 - D) * j))
    
    Hcount = len(hikers)
    y = Hcount
    
    for i in range(Hcount):
        score = 0
        # Try to finish just after ith hiker.
        for j in range(Hcount):
            if i == j:
                continue
            # How many times will we cross jth hiker?
            crosses = (hikers[i][2] - hikers[j][2]) // 360 // hikers[j][1]
            score += abs(crosses)
        y = min(y, score)
    
    print('Case #' + str(x) + ':', y)
