import sys

from math import *

def lg(a) :
    sys.stderr.write(str(a)+"\n")

T = int(sys.stdin.readline())
for testNr in range(1,T+1) :
    print "Case #%d:" % testNr ,
    x,s,r,t,n = map(int,sys.stdin.readline().split())
#    print
#    print x,s,r,t,n
    ws = []
    for i in range(n) :
	b,e,w = map(int,sys.stdin.readline().split())
	ws.append((w,e-b))
    wlen = sum([ l for (w,l) in ws ])
    ws.append((0,x-wlen))
    ws.sort()
#    print ws
    time = float(t)
    t = float(t)
    total = 0.0
    for w,l in ws :
#	print "gaz left:",time
	if time<1e-7 :
	    needed = float(l)/(s+w)
#	    print "no spiritusz",needed
	    total += needed
	    continue
	if (r+w)*time >= l :
	    needed = float(l)/(r+w)
#	    print "fullgaz",needed
	    time -= needed
	    total += needed
	else :
	    needed = time
#	    print "maradt:",needed
	    X = (float(l)-time*(r+w))/(s+w)
#	    print "leeresztett:",X
	    needed += X
	    time = 0.0
	    total += needed
    print total
