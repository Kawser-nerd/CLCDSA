#!/usr/bin/python

fin = open("d.in", "r")
fout = open("d.out", "w")

def all_perms(str):
    if len(str) <=1:
        yield str
    else:
        for perm in all_perms(str[1:]):
            for i in range(len(perm)+1):
                yield perm[:i] + str[0:1] + perm[i:]


n = int(fin.readline())
for i in xrange(1, n+1):
	k = int(fin.readline())
	s = fin.readline().strip()
	print k, s
	
	best = 10000000
	for perm in all_perms(range(k)):
		last = None
		count = 0
		ns = s
		while len(ns):
			for p in perm:
				if ns[p] != last:
					count += 1
					last = ns[p]
			ns = ns[k:]
			
		best = min(best, count)
	print best
	print >> fout, "Case #%d: %d" % (i, best)