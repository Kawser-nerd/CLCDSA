tn = input()
for loop in xrange(1,tn+1):
	print "Case #%d:" % loop,
	n = input()
	ps = []
	for i in xrange(n):
		line = raw_input()
		x, y, z, p = [float(x) for x in line.split()]
		ps.append((x,y,z,p))
	
	lp = 0.0
	rp = 3000000.0
	while lp + 0.0000008 < rp:
		mp = (lp + rp) / 2
		mpi = mp * ps[0][3]
		c1 = ps[0][0]+ps[0][1]+ps[0][2]+mpi
		c2 = ps[0][0]+ps[0][1]-ps[0][2]+mpi
		c3 = ps[0][0]-ps[0][1]+ps[0][2]+mpi
		c4 = -ps[0][0]+ps[0][1]+ps[0][2]+mpi
		c5 = ps[0][0]+ps[0][1]+ps[0][2]-mpi
		c6 = ps[0][0]+ps[0][1]-ps[0][2]-mpi
		c7 = ps[0][0]-ps[0][1]+ps[0][2]-mpi
		c8 = -ps[0][0]+ps[0][1]+ps[0][2]-mpi
		for i in xrange(1, n):
			mpi = mp * ps[i][3]
			cc1 =  ps[i][0]+ps[i][1]+ps[i][2]+mpi
			cc2 =  ps[i][0]+ps[i][1]-ps[i][2]+mpi
			cc3 =  ps[i][0]-ps[i][1]+ps[i][2]+mpi
			cc4 = -ps[i][0]+ps[i][1]+ps[i][2]+mpi
			cc5 =  ps[i][0]+ps[i][1]+ps[i][2]-mpi
			cc6 =  ps[i][0]+ps[i][1]-ps[i][2]-mpi
			cc7 =  ps[i][0]-ps[i][1]+ps[i][2]-mpi
			cc8 = -ps[i][0]+ps[i][1]+ps[i][2]-mpi
			if c1 > cc1: c1 = cc1
			if c2 > cc2: c2 = cc2
			if c3 > cc3: c3 = cc3
			if c4 > cc4: c4 = cc4
			if c5 < cc5: c5 = cc5
			if c6 < cc6: c6 = cc6
			if c7 < cc7: c7 = cc7
			if c8 < cc8: c8 = cc8
			if c1 < c5:
				break
			if c2 < c6:
				break
			if c3 < c7:
				break
			if c4 < c8:
				break
		else:
			rp = mp
			continue
		lp = mp
	print mp


