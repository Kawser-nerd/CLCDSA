import sys

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    print "Case #%d:" % testNr ,
    n = int(sys.stdin.readline())
    a = map(int,sys.stdin.readline().split())
    nf = 0
    for i,e in enumerate(a) :
	if i+1!=e :
	    nf += 1
    print float(nf)
