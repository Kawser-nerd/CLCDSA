import sys

C=int(sys.stdin.readline())
for case in range(C):
	N, K, B, T = map(int, sys.stdin.readline().split())
	X = map(int, sys.stdin.readline().split())
	V = map(int, sys.stdin.readline().split())
	swaps = 0
	barriers = 0
	made = 0
	for i in range(len(X)-1, -1, -1):
		stops = X[i] + V[i]*T 
#		print "%d stops at %d" % (i, stops)
		if stops >= B:
			swaps += barriers
			made += 1
		else:
			barriers += 1
		if made == K:
			break
	r = swaps if made == K else "IMPOSSIBLE"	
	print "Case #%d: %s" % (case+1, r)