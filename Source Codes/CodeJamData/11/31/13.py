class streamreader:
	def __init__(_,s): _.t=(t for t in s.read().split())
	def __div__(_,t): return (t)(_.t.next())

import sys
sr = streamreader(sys.stdin)

for tc in xrange(sr/int):
	def split(s):
		return [c for c in s]

	n, m = sr/int, sr/int
	x = [split('.' * (m + 2))]
	for i in xrange(n):
		x.append(split('.' + sr/str + '.'))
	x.append(x[0])
	
	def pr(x):
		for l in x[1:-1]:
			print ''.join(l[1:-1])
	
	for i in xrange(1, n + 1):
		for j in xrange(1, m + 1):
			if x[i][j] == '#':
				if x[i-1][j] != '#' and x[i][j-1] != '#':
					if x[i+1][j] == '#' and x[i][j+1] == '#' and x[i+1][j+1] == '#':
						x[i][j] = '/'
						x[i+1][j] = '\\'
						x[i][j+1] = '\\'
						x[i+1][j+1] = '/'
			
	possible = True
	for line in x:
		if ''.join(line).count('#') > 0:
			possible = False
			break
			
	print 'Case #%d:' % (tc + 1)
	if possible:
		pr(x)
	else:
		print 'Impossible'