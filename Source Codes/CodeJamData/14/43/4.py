#!/usr/bin/env python3

def upheap(heap, refs, i):
    while i > 0:
        j = (i-1) // 2;
        if heap[i] >= heap[j]:
            break
        
        heap[i], heap[j] = heap[j], heap[i]
        refs[heap[i][1]] = i
        refs[heap[j][1]] = j
        i = j

def popheap(heap, refs):
    i = 0
    j = len(heap)-1
    heap[i], heap[j] = heap[j], heap[i]
    refs[heap[i][1]] = i
    refs[heap[j][1]] = j
    del heap[j]
    
    while 2*i+1 < len(heap):
        j = 2*i + 1;
        if j+1 < len(heap) and heap[j+1] < heap[j]:
            j = j+1
        if heap[i] <= heap[j]:
            break
        
        heap[i], heap[j] = heap[j], heap[i]
        refs[heap[i][1]] = i
        refs[heap[j][1]] = j
        i = j

def dist(b1, b2):
    return max(b1[0] - b2[2], b2[0] - b1[2], b1[1] - b2[3], b2[1] - b1[3]) - 1

for ti in range(1, int(input())+1):
    w, h, b = map(int, input().split())
    
    buildings = [[int(x) for x in input().split()] for i in range(b)]
    score = [bd[0] for bd in buildings]
    
    heap = [[score[i], i] for i in range(b)]
    heap.sort()
    refs = [0] * b
    for i in range(b):
        refs[heap[i][1]] = i
    
    while len(heap) > 0:
        bestscore, i = heap[0]
        popheap(heap, refs)
        
        for j in range(b):
            if j == i:
                continue
            newscore = bestscore + dist(buildings[i], buildings[j])
            if score[j] > newscore:
                score[j] = newscore
                heap[refs[j]][0] = newscore
                upheap(heap, refs, refs[j])
    
    best = w
    for i in range(b):
        newscore = score[i] + w - buildings[i][2] - 1
        if newscore < best:
            best = newscore
    print('Case #' + str(ti) + ': ' + str(best))
