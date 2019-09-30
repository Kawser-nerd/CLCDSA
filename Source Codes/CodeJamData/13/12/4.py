def max_index(vals, st, en):
	m = -1
	maxi = -1
	for i in xrange(st, en):
		if vals[i] > m:
			m = vals[i]
			maxi = i
	return maxi

def fn(E, R, N, vals, st, en, stE, enE):
	if en-st == 0:
		return 0
	maxi = max_index(vals, st, en)
	numBefore = maxi-st
	numAfter = en-maxi
	energy = min(E, stE + numBefore*R)
	energy = min(energy, energy-(enE - numAfter*R))
	reqEnergy = min(E, stE+numBefore*R)
	return energy*vals[maxi] + fn(E, R, N, vals, st, maxi, stE, reqEnergy) + \
		fn(E, R, N, vals, maxi+1, en, reqEnergy-energy+R, enE)


T = int(raw_input())
for z in xrange(1, T+1):
	E, R, N = [int(i) for i in raw_input().split()]

	vals = [int(i) for i in raw_input().split()]
	print "Case #%d: %d"%(z, fn(E, R, N, vals, 0, N, E, 0))