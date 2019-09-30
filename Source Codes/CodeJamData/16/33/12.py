def solve(a):
 	J, P, S, K = [int(w) for w in a.split(" ")[:4]]
	K = min(S, K)
	print J * P * K
	for x in xrange(J):
		for y in xrange(P):
			for z in xrange(K):
				print x + 1, y + 1, (x + y + z) % S + 1

file = open("C-large.in", "r")
a = file.readlines()
T = int(a[0])
for i in xrange(T):
	print "Case #%d:" % (i+1),
	solve(a[i+1])
