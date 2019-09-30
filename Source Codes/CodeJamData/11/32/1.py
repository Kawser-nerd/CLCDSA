#!/usr/bin/python
#use globals

def make():
    return [a[i%C] for i in range(N)]

def solve():
    b = make() 
    i = 0
    time = 0
    while time < t and i < N:
        time += 2*b[i]
        i += 1
    b = [(time - t)/2.0] + b[i:]
    b.sort()
    b.reverse()
    return int(t + sum(b[:L]) + sum(b[L:])*2)

r = input()
for case in range(1,r+1):
    l = map(int,raw_input().split())
    L,t,N,C = tuple(l[:4])
    a = l[4:]
    print "Case #%s: %s" % (case, solve())
