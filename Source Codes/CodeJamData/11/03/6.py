import sys

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    print "Case #%d:" % testNr ,
    n = int(sys.stdin.readline())
    a = map(int,sys.stdin.readline().split())
    x = 0
    for e in a :
	x ^= e
    if x!=0 :
	print "NO"
    else :
	print sum(a)-min(a)
