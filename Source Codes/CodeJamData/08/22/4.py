def isset(a, bit): return ((a >> bit) & 1) > 0
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

def gcd(a, b):
	if (a < b):
		(a, b) = (b, a)
	while (True):
		if (b == 0): return a;
		a %= b;
		(a, b) = (b, a)

def genprimes(a):
	res = {}
	r = []
	for i in xrange(2, a + 1):
		if i in res: continue
		r.append(i)
		for j in xrange(i + i, a + 1, i):
			res[j] = True
	return r

par = {}
def getp(p):
	if (par[p] == p): return p
	res = getp(par[p])
	par[p] = res
	return res
	

def run_test():
	(A, B, P) = readlinearray(int)
	for i in xrange(A, B + 1):
		par[i] = i
	did = True
	res = B - A + 1
	while did:
		did = False
		for i in xrange(A, B + 1):
			for p in pr:
				if p < P: continue
				if (i % p != 0): continue
				for j in xrange(i, B + 1, p):
					if (getp(i) == getp(j)): continue
					par[getp(i)] = getp(j)
					res -= 1
					did = True
	return res

if __name__ == "__main__":
	pr = genprimes(1000)
	tests = int(raw_input())
	for test in range(tests):
		res = run_test()
		print "Case #%d: %s" % (test + 1, res)

