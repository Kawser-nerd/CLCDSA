#!/usr/bin/env python3

# Google Code Jam Round 1B 2016
# Problem C. Technobabble
# Solution in Python
# By Smithers

def search(i):
    firstfrom = [None] * len(firstmap)
    secondfrom = [None] * len(secondmap)
    queue = [(0, i)]
    firstfrom[i] = -1
    
    while queue:
        which, j = queue[-1]
        queue.pop()
        
        if which == 0:
            for k in range(len(secondmap)):
                if matrix[j][k] != 1:
                    continue
                if secondfrom[k] is not None:
                    continue
                if not secondmatched[k]:
                    secondmatched[k] = 1
                    matrix[j][k] = 2
                    k = firstfrom[j]
                    while k != -1:
                        matrix[j][k] = 1
                        j = secondfrom[k]
                        matrix[j][k] = 2
                        k = firstfrom[j]
                    firstmatched[j] = 1
                    return
                secondfrom[k] = j
                queue.append((1, k))
        else:
            for k in range(len(firstmap)):
                if matrix[k][j] != 2:
                    continue
                if firstfrom[k] is not None:
                    continue
                firstfrom[k] = j
                queue.append((0, k))

for x in range(1, int(input()) + 1):
    n = int(input())
    
    firstmap = {}
    secondmap = {}
    
    topicgrid = []
    
    for i in range(n):
        topic = input().split()
        if topic[0] not in firstmap:
            firstmap[topic[0]] = len(firstmap)
        if topic[1] not in secondmap:
            secondmap[topic[1]] = len(secondmap)
        topicgrid.append((firstmap[topic[0]], secondmap[topic[1]]))
    
    matrix = [[0] * len(secondmap) for _ in range(len(firstmap))]
    for topic in topicgrid:
        matrix[topic[0]][topic[1]] = 1
    
    firstmatched = [0] * len(firstmap)
    secondmatched = [0] * len(secondmap)
    
    for i in range(len(firstmap)):
        if not firstmatched[i]:
            search(i)
    
    print('Case #' + str(x) + ':', n - (len(firstmap) + len(secondmap) - sum(firstmatched)))
