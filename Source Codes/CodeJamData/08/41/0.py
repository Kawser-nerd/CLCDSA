FI = 'A-large.in'
AND=1
OR=0
VALUE=-1
def make1(node):
	g,c,v,l,r = node
	if v==1:
		return 0
	if g==VALUE:
		return 100000
	if g == OR:
		return min(make1(l), make1(r))
	if c:
		return 1 + min(make1(l), make1(r))
	else:
		return make1(l) + make1(r)

def make0(node):
	g,c,v,l,r = node
	if v==0:
		return 0
	if g==VALUE:
		return 100000
	if g == AND:
		return min(make0(l), make0(r))
	if c:
		return 1 + min(make0(l), make0(r))
	else:
		return make0(l) + make0(r)

def case(fi, fo, n):
	M,V = map(int, fi.readline().split())
	nodes = []
	for i in xrange((M-1)/2):
		g,c = map(int, fi.readline().split())
		nodes.append([g,c,0,0,0])
	for i in xrange((M+1)/2):
		v = int(fi.readline())
		nodes.append([VALUE,0,v,None,None])
	for i in xrange((M-1)/2-1, -1, -1):
		l = nodes[i][3] = nodes[2*i+1]
		r = nodes[i][4] = nodes[2*i+2]
		if nodes[i][0] == AND:
			nodes[i][2] = min(l[2], r[2])
		else:
			nodes[i][2] = max(l[2], r[2])

	if V==0:
		val = make0(nodes[0])
	else:
		val = make1(nodes[0])

	if val >= 100000:
		fo.write('Case #%d: IMPOSSIBLE\n' % n)
	else:
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
