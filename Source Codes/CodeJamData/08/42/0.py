FI = 'B-large.in'
def case(fi, fo, num):
	N,M,A = map(int, fi.readline().split())
	for X in xrange(1, N+1):
		for Y in xrange(A/X, M+1):
			for x in xrange(1, X+1):
				y = (X*Y-A)/x
				if y >= 0 and A == X*Y - x*y:
					fo.write('Case #%d: 0 0 %d %d %d %d\n' % (num, x, Y, X, y))
					return
	fo.write('Case #%d: IMPOSSIBLE\n' % num)

# ---

def rl(f, n):
	return [f.readline() for i in xrange(n)]
def zw(fs, es):
	return [f(e) for f,e in zip(fs, es)]
def cases(fi, fo):
	for i in xrange(int(fi.readline())):
		case(fi, fo, i+1)

fi = open(FI)
fo = open('out.txt', 'w')
cases(fi, fo)
fi.close()
fo.close()

f = open('out.txt')
print f.read()
