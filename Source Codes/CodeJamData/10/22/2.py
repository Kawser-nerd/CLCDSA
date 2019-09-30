#!/usr/bin/python


c = input()

for i in range(c):
    n, k, b, t = map(int, raw_input().strip('\n').split())
    x = map(int, raw_input().strip('\n').split())
    v = map(int, raw_input().strip('\n').split())

    ok = []
    for j in range(n):
        if x[j] + v[j]*t >= b: ok.append( True )
        else: ok.append( False )
    
    res = 0
    minus = 0
    for cur in reversed(ok):
        if k <= 0:break
        if cur:
            res += minus
            k -= 1
        else:
            minus += 1

    print 'Case #' + str(i + 1) + ':',
    if k == 0: print str(res)
    else: print "IMPOSSIBLE"



