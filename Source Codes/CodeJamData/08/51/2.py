FI = 'A-large.in'

def case(fi, fo, n):
	Hor = [[] for i in xrange(6002)]
	Ver = [[] for i in xrange(6002)]
	L = int(fi.readline())
	x = 3000
	y = 3000
	dir = 1 # 0=east, 1=north, 2=west, 3=south
	while L > 0:
		lis = fi.readline().split()
		L -= len(lis)/2
		i = 0
		while i < len(lis):
			for j in xrange(int(lis[i+1])):
				for c in lis[i]:
					if c=='F':
						if dir==0:
							Ver[x].append(y)
							x += 1
						elif dir==1:
							Hor[y].append(x)
							y += 1
						elif dir==2:
							Ver[x-1].append(y)
							x -= 1
						elif dir==3:
							Hor[y-1].append(x)
							y -= 1
					elif c=='L':
						dir = (dir+1) % 4
					elif c=='R':
						dir = (dir+3) % 4
			i += 2
	
	res = 0
	Horints = [[] for i in xrange(6002)]
	for (idx,L) in enumerate(Hor):
		L.sort()
		assert(len(L) % 2 == 0)
		i=1
		while i<len(L)-1:
			Horints[idx].append((L[i],L[i+1]))
			res += L[i+1] - L[i]
			i += 2
	for (idx,L) in enumerate(Ver):
		L.sort()
		assert(len(L) % 2 == 0)
		i=1
		while i<len(L)-1:
			res += L[i+1] - L[i]
			for j in xrange(L[i], L[i+1]):
				for (y1,y2) in Horints[j]:
					if y1 <= idx < y2:
						res -= 1
						break
			i += 2

	fo.write('Case #%d: %d\n' % (n, res))

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
