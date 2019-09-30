import psyco
def main():
	bcd = {}
	def bc(n):
		if n in bcd:
			return bcd[n]
		nn = n
		s = 0
		while n:
			if n&1:
				s += 1
			n /= 2
		bcd[nn] = s
		return s
	N = input()
	for loop in xrange(1, N+1):
		print "Case #%d:" % loop,
		H, W = [int(x) for x in raw_input().split()]
		m = []
		for i in xrange(H):
			m.append(raw_input().strip())
		def bit(n):
			s = 0
			for i in xrange(H):
				s <<= 1
				s += 1 if m[i][n] == 'x' else 0
			return s
		d = {}
		HH = 1 << H
		for h in xrange(HH):
			if h & bit(0):
				# blocked
				continue
			#pat = (h | (h << 1) | (h >> 1)) % HH
			d[h] = bc(h)
		#print d

		for wl in xrange(1,W):
			dd = {}
			for h in xrange(HH):
				if h & bit(wl):
					# blocked
					continue
				pat = (h | (h << 1) | (h >> 1)) % HH

				maxx = -1
				for k, v in d.iteritems():
					if k & pat:
						continue
					maxx = max(maxx, v)
				if maxx >= 0:
					try:
						dd[h] = max(dd[pat], bc(h) + maxx)
					except:
						dd[h] = bc(h) + maxx

			d = dd
			#print d

		print max(d.itervalues())

psyco.full()
main()
