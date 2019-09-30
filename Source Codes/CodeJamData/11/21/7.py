import sys
import fractions

T = int(raw_input())

for tt in xrange(1, T + 1):
	n = int(raw_input())
	a = []
	for i in xrange(0, n):
		a.append([-1 if x == '.' else int(x) for x in raw_input().split()[0]])
		a[i][i] = -1
	wp = [0] * n
	wp2 = []
	owp = [0] * n
	oowp = [0] * n
	for i in xrange(0, n):
		wp2.append([0] * n)
		total = 0
		won = 0
		for j in xrange(0, n):
			if a[i][j] != -1:
				total += 1
				if a[i][j]:
					won += 1
		if total:
			wp[i] = won / (1.0 * total)
		for k in xrange(0, n):
			total = 0
			won = 0
			for j in xrange(0, n):
				if j != k and a[i][j] != -1:
					total += 1
					if a[i][j]:
						won += 1
			if total:
				wp2[i][k] = won / (1.0 * total)
	for i in xrange(0, n):
		total = 0
		for j in xrange(0, n):
			if i != j and a[i][j] != -1:
				total += 1
				owp[i] += wp2[j][i]
		if total:
			owp[i] /= total
	for i in xrange(0, n):
		total = 0
		for j in xrange(0, n):
			if a[i][j] != -1:
				total += 1
				oowp[i] += owp[j]
		if total:
			oowp[i] /= total
	print 'Case #%d:' % (tt)
	for i in xrange(0, n):
		rpi = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]
		print rpi
	