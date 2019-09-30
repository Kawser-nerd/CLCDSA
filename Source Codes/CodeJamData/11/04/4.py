#!/usr/bin/python

def solve(L):
    s = sorted(L)
    return len([i for i in range(len(L)) if L[i] != s[i]])

r = int(input())
for i in range(1,r+1):
    input()
    L = map(int,raw_input().split(' '))
    print "Case #%s: %.6f" % (i, solve(L)) 
