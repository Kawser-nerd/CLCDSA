# -*- coding: utf-8 -*-
fin = open("c.in","r")
T = int(fin.readline())

global p, q, prisoners, cc

def cost(a, b):
    if (a,b) in cc:
        return cc[(a,b)]
    
    if b - a <= 1:
        return 0
    
    minc = None
    for p in range(a+1,b):
        c = cost(a,p) + cost(p,b) + prisoners[b] - prisoners[a] - 2
        if minc is None or c < minc:
            minc = c
    
    cc[(a,b)] = minc
    return minc
    
for i in range(T):
    cc = {}
    p, q = map(int, fin.readline().split())
    prisoners = [0] + map(int, fin.readline().split()) + [p+1]
    p += 2
    q += 2
    print "Case #%d: %d" % (i+1, cost(0, q-1))