#! /usr/bin/python
# -*-coding:Utf-8 -*

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def rec(toys, boxes, t1, t2, b1, b2):
    global N, M, memo
    if (t1, t2, b1, b2) in memo:
        return memo[(t1, t2, b1, b2)]
    if t1 == M or b1 == N:
        r = 0
    else:
        if toys[t1][1] == boxes[b1][1]:
            lt = toys[t1][0] - t2
            lb = boxes[b1][0] - b2
            if lt < lb:
                r = lt + rec(toys, boxes, t1+1, 0, b1, b2+lt)
            elif lb < lt:
                r = lb + rec(toys, boxes, t1, t2+lb, b1+1, 0)
            else:
                r = lb + rec(toys, boxes, t1+1, 0, b1+1, 0)
        else:
            m1 = rec(toys, boxes, t1+1, 0, b1, b2)
            m2 = rec(toys, boxes, t1, t2, b1+1, 0)
            r = max(m1, m2)
    memo[(t1, t2, b1, b2)] = r
    return r


T = readint()
for t in range(T):
    print 'Case #'+str(t+1)+':',
    
    N,M = readarray(int)
    input = readarray(int)
    boxes = []
    for i in range(0, 2*N, 2) :
        boxes.append((input[i], input[i+1]))
        i+=1
    input = readarray(int)
    toys = []
    for i in range(0, 2*M, 2):
        toys.append((input[i], input[i+1]))
        i+=1
    memo = dict()
    print rec(toys, boxes, 0, 0, 0, 0)
    
