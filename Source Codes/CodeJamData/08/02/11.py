#!/usr/bin/python
import sys

def get_closest(times, minutes):
    # TODO: bin search
    if not times or times[-1][0] < minutes:
        return None
    
    if times[0][0] >= minutes:
        return 0
    
    #for i, (dep, arr) in enumerate(times):
    #    if dep >= minutes:
    #        return i
    
    
    l, r = 0, len(times)
    while abs(l-r)>1:
        m = (l+r)/2
        if times[m][0] >= minutes:
            r = m
        else:
            l = m
        #print >> sys.stderr, l, r, m
    assert(times[r-1][0] < minutes)
    assert(times[r][0] >= minutes)
    return r
    return None
    

def filltrain(NA_times, NB_times, T, mem, fromA=True):
    #print NA_times, NB_times
    NA_times, NB_times = NA_times[:], NB_times[:]
    # assume it A
    if fromA:
        XX_times = [NA_times, NB_times]
        r = (1,0)
    else:
        XX_times = [NB_times, NA_times]
        r = (0, 1)
    minutes = 0
    while True:
        i = get_closest(XX_times[0], minutes)
        if i is None:
            break
        #dep, arr = XX_times[0].pop(i)
        dep, arr = XX_times[0][i]
        XX_times[0][i:] =  XX_times[0][i+1:]
        
        minutes = arr + T
        XX_times[0], XX_times[1] = XX_times[1], XX_times[0]
    
    if not XX_times[0] and not XX_times[1]:
        return r
    
    a = (sys.maxint, sys.maxint)
    b = (sys.maxint, sys.maxint)
    if NA_times:
        k = repr((tuple(NA_times), tuple(NB_times), True))
        if k not in mem:
            mem[k] = filltrain(NA_times, NB_times, T, mem, fromA=True)
        a = mem[k]
    if NB_times:
        k = repr((tuple(NA_times), tuple(NB_times), False))
        if k not in mem:
            mem[k] = filltrain(NA_times, NB_times, T, mem, fromA=False)
        b = mem[k]
    if sum(a) <= sum(b):
        return (a[0]+r[0], a[1]+r[1])
    return (b[0]+r[0], b[1]+r[1])

def tominutes(s):
    hour, minutes = map(int, s.split(':'))
    return hour*60 + minutes

def fromminutes(m):
    hour, minutes = divmod(m, 60)
    return "%02i:%02i" % (hour, minutes)

for case in range(input()):
    T = input()
    NA, NB = map(int, raw_input().split())
    NA_times = [ map(tominutes, raw_input().split()) for i in range(NA) ]
    NB_times = [ map(tominutes, raw_input().split()) for i in range(NB) ]
    
    NA_times.sort(key=lambda a:a[0])
    NB_times.sort(key=lambda a:a[0])
    
    a = filltrain(NA_times, NB_times, T, {}, fromA=True)
    b = filltrain(NA_times, NB_times, T, {}, fromA=False)
    if sum(a) <= sum(b):
        r = a 
    else:
        r = b
    print "Case #%i: %i %i" % (case+1, r[0], r[1])
    
