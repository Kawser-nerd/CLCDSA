FI = 'D-small-attempt0.in'

rocks = {}
def dp(x,y):
	global rocks
	if x<1 or y<1:
		return 0
	if (x,y) in rocks:
		return rocks[(x,y)]
	else:
		rocks[(x,y)] = (dp(x-2,y-1) + dp(x-1,y-2)) % 10007
		return rocks[(x,y)]

def case(fi, fo, n):
	global rocks
	rocks = {}
	rocks[(1,1)] = 1
	H,W,R = map(int, fi.readline().split())
	for i in xrange(R):
		x,y = map(int, fi.readline().split())
		rocks[(x,y)] = 0
	val = dp(H, W)
	fo.write('Case #%d: %d\n' % (n, val))

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
