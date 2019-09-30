# -*- coding: utf-8 -*-
import sys


def parent(path):
    return path[:path.rindex("/")]
    
    
fin = sys.stdin
T = int(fin.readline())
    
for case in range(1,T+1):
    N, M = map(int, fin.readline().split())
    
    current = set()
    current.add("")
    
    for i in range(N):
        path = fin.readline().strip()
        while not path in current:
            current.add(path)
            path = parent(path)
        
    count = 0
    for i in range(M):
        path = fin.readline().strip()
        
        while not path in current:
            current.add(path)
            path = parent(path)
            count += 1
        
    print "Case #%d: %s" % (case, count)
