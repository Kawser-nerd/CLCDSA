# -*- coding: utf-8 -*-
import sys
fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    N, K, B, T = map(int, fin.readline().split())
    x = map(int, fin.readline().split())
    v = map(int, fin.readline().split())
    chicks = zip(x, v)
    chicks.sort(reverse=True)
    
    slow_counter = 0
    
    swap_counter = 0
    
    safe_counter = 0
    for c in chicks:
        if c[0] + c[1]*T >= B:
            swap_counter += slow_counter
            safe_counter += 1
        else:
            slow_counter += 1
        if safe_counter >= K:
            break
    
    if safe_counter >= K:
        result = swap_counter
    else:
        result = "IMPOSSIBLE"
    print "Case #%d: %s" % (case, result)
