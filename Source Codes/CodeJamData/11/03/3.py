#!/usr/bin/python

def solve(L):
    xors = reduce(lambda a,b: a^b,L)
    if xors != 0:
        return 'NO'
    return sum(L) - min(L) 

r = int(input())
for i in range(1,r+1):
    input()
    L = map(int,raw_input().split(' '))
    print "Case #%s: %s" % (i, solve(L)) 
