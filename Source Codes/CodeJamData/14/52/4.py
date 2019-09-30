#!/usr/bin/env python3

# Google Code Jam Round 3 2014
# Problem B. Last Hit
# Solution in Python
# By Smithers

for ti in range(1, int(input()) + 1):
    p, q, n = [int(x) for x in input().split()]
    
    bests = [(0, 1)]
    for i in range(n):
        h, g = [int(x) for x in input().split()]
        
        towershots = (h + q-1) // q
        bestdiff = 100
        for j in range(towershots):
            k = (h - q*j + p-1) // p
            if k - j < bestdiff:
                bestdiff = k - j
        
        newbests = []
        for best in bests:
            newbests.append((best[0], best[1] + towershots))
            if best[1] >= bestdiff:
                newbests.append((best[0] + g, best[1] - bestdiff))
        
        newbests = sorted(newbests)
        last = newbests[-1]
        bests = [last]
        for i in reversed(range(0, len(newbests)-1)):
            if newbests[i][0] > last[0] or newbests[i][1] > last[1]:
                bests.append(newbests[i])
                last = newbests[i]
    
    print('Case #' + str(ti) + ':', bests[0][0])
