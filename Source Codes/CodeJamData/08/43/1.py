FI = 'C-small-attempt0.in'

def minpower(ships, x, y, z):
	maxp = 0
	for (x1,y1,z1,p) in ships:
		maxp = max(maxp, (abs(x1-x)+abs(y1-y)+abs(z1-z))/float(p))
	return maxp

def case(fi, fo, n):
	N = int(fi.readline())
	ships = []
	for i in xrange(N):
		x,y,z,p = map(int, fi.readline().split())
		ships.append((x,y,z,p))
	xl = yl = zl = 0.0
	iv = 1000000.0
	minp = 10000000.0
	while iv > 0.0000001:
		minp = 10000000.0
		x1 = xl + iv/4
		x2 = xl + 3*iv/4
		y1 = yl + iv/4
		y2 = yl + 3*iv/4
		z1 = zl + iv/4
		z2 = zl + 3*iv/4
		for x in [x1,x2]:
			for y in [y1,y2]:
				for z in [z1,z2]:
					curp = minpower(ships,x,y,z)
					if curp < minp:
						xm = x
						ym = y
						zm = z
						minp = curp
		xl = xm - iv/4
		yl = ym - iv/4
		zl = zm - iv/4
		iv /= 2
	fo.write('Case #%d: %f\n' % (n, minp))


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
