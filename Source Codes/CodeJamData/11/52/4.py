def doit(a):
	if not a: return 100500
	global mem
	if a in mem: return mem[a]
	b = list(a)
	x = a[0]
	res = 0
	for i in xrange(len(a)):
		if x + i not in b: break
		b.remove(x + i)
		res = max(res, min(i + 1, doit(tuple(b))))
	mem[a] = res
	return res

def run():
	global mem
	mem = {}
	a = map(int, raw_input().split())
	n = a[0]
	del a[0]
	if n == 0: return 0
	a.sort()
	return doit(tuple(a))
	

for test in xrange(input()):
	print "Case #%d: %d" % (test + 1, run())