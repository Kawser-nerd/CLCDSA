import sys;
rline = sys.stdin.readline

N = int(rline())

for cn in range(1,N+1):
	R = int(rline())
	a = set()
	b = set()
	for i in range(R):
		v = rline().split()
		vi = [int(i) for i in v]
		(q,e,w,r) = (vi[0],vi[1],vi[2],vi[3])
		for x in range(q,w+1):
			for y in range(e,r+1):
				a.add((x,y))
	out = 0
	cas = 0
	while True:
		if cas == 0:
			if len(a) == 0:
				break
			b = set()
			for x,y in a:
				if (x-1,y) in a or (x,y-1) in a:
					b.add((x,y))
				if (x-1,y+1) in a:
					b.add((x,y+1))

		else:
			if len(b) == 0:
				break
			a = set()
			for x,y in b:
				if (x-1,y) in b or (x,y-1) in b:
					a.add((x,y))
				if (x-1,y+1) in b:
					a.add((x,y+1))
		out += 1
		cas = 1 - cas
	print "Case #%d: %d" % (cn,out)
