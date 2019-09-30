FI = 'D-small-attempt0.in'

def perm(l):
    sz = len(l)
    if sz <= 1:
        return [l]
    return [p[:i]+[l[0]]+p[i:] for i in xrange(sz) for p in perm(l[1:])]

def case(fi, fo, n):
	k = int(fi.readline())
	S = fi.readline().strip()
	S2 = ['']*len(S)
	minl = len(S)
	for L in perm(range(k)):
		for i in xrange(len(S)):
			S2[i] = S[i-i%k + L[i%k]]
		curc = S2[0]
		curl = 1
		for i in xrange(1, len(S2)):
			if curc != S2[i]:
				curl += 1
			curc = S2[i]
		minl = min(minl, curl)

	fo.write('Case #%d: %d\n' % (n, minl))


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
