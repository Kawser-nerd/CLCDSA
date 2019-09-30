# -*- coding: utf-8 -*-
import sys
import math

cmem = {}
def C(total, choose):
    if total < choose:
        return 0
    if (total, choose) in cmem:
        return cmem[(total, choose)]
    c = (math.factorial(total) / math.factorial(choose) / math.factorial(total - choose)) % 100003
    cmem[(total, choose)] = c
    return c
    
mem = {}
COUNTER = 0
def g(n, rank):
    global COUNTER
    if rank == 1:
        return 1
    
    if (n, rank) in mem:
        return mem[(n, rank)]
        
    total = 0
    for i in range(1, rank):
        COUNTER += 1
        total += C(n - rank - 1, rank - i - 1) * g(rank, i)
    mem[(n, rank)] = total
    return total % 100003

fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    N = int(fin.readline())
    
    total = 0
    for i in range(1, N):
        total += g(N, i)
    print "Case #%d: %s" % (case, total % 100003)
#print COUNTER