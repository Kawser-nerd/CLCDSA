w = 0
qn = 0
m = []
dir = (1,0),(0,1),(-1,0),(0,-1)

nums = set(list('0123456789'))

def main():
	loopN = int(raw_input())
	for q in xrange(loopN):
		print 'Case #%d:' % (q+1)
		m = []
		w, qn = [int(x) for x in raw_input().split()]
		for i in xrange(w):
			m.append(raw_input())
		c = {}
		for i in xrange(w):
			for j in xrange(w):
				if m[i][j] in '0123456789':
					c[(i,j)] = {int(m[i][j]): m[i][j]}

		qs = [int(x) for x in raw_input().split()]
		oqs = qs[:]
		qm = dict((x, None) for x in qs)
		while qs:
			for qv in qs:
				for p, v in c.iteritems():
					if qv in v:
						if qm[qv] is None:
							qm[qv] = v[qv]
						elif qm[qv] > v[qv]:
							qm[qv] = v[qv]
			for i in xrange(len(qs)-1, -1, -1):
				if qm[qs[i]] is not None:
					del qs[i]
			if not qs: break
			nc = {}
			for k in c.iterkeys():
				y, x = k
				mv = int(m[y][x])
				nc[k] = {}
				for dx, dy in dir:
					nx = x + dx
					ny = y + dy
					if nx < 0 or ny < 0 or nx >= w or ny >= w: continue
					for ndx, ndy in dir:
						nnx = nx + ndx
						nny = ny + ndy
						if nnx < 0 or nny < 0 or nnx >= w or nny >= w: continue
						op = m[ny][nx]
						for ck, cv in c[(nny,nnx)].iteritems():
							if op == '+':
								newv = ck + mv
							else:
								newv = ck - mv
							if newv in c[k]:
								continue
							news = cv + op +m[y][x]
							if newv in nc[k]:
								if news < nc[k][newv]:
									nc[k][newv] = news
							else:
								nc[k][newv] = news
			c = nc
		for qv in oqs:
			print qm[qv]



if __name__ == '__main__':
	main()
