def bitcount(n):
	if n == 0:
		return 0
	return bitcount(n >> 1) + (n & 1)

def ent(x): return int(x, 2)

def uf(x):
	if len(x) < l:
		return '0'*(l - len(x)) + x
	return x

def ff(x):
	return [uf(bin(xx)[2:]) for xx in x]

def attempt(xz,yz,i):
	#print "trying", ff(xz), ff(yz), i, n, l
	if len(xz) == 1 or i == l:
		mask = xz[0] ^ yz[0]
		xm = sorted(x ^ mask for x in xs)
		if xm == ys:
			return bitcount(mask)
		return None

	xz1 = [x for x in xz if ((x>>i)&1) == 1]
	xz0 = [x for x in xz if ((x>>i)&1) == 0]
	yz1 = [y for y in yz if ((y>>i)&1) == 1]
	yz0 = [y for y in yz if ((y>>i)&1) == 0]

	xzt = min(xz1, xz0, key=len)
	if len(xzt) == 0:
		gg = attempt(xz,yz,i+1)
		return gg

	ans = None
	if len(xzt) == len(yz0):
		anz = attempt(xzt, yz0, i+1)
		if anz is not None and (ans is None or ans > anz):
			ans = anz
	if len(xzt) == len(yz1):
		anz = attempt(xzt, yz1, i+1)
		if anz is not None and (ans is None or ans > anz):
			ans = anz
	return ans

for cas in xrange(1,input()+1):
	n, l = map(int, raw_input().strip().split())
	xs = map(ent, raw_input().strip().split())
	ys = map(ent, raw_input().strip().split())
	ys = sorted(ys)
	ans = attempt(xs,ys,0)
	print "Case #%s:" % cas,
	if ans is None:
		print "NOT POSSIBLE"
	else:
		print ans

