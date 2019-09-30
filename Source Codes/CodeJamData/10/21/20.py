import sys

fin = sys.stdin

tc = int(fin.readline())

def go(dirs, seq):
	ans = 0
	cur = dirs
	for d in seq:
		if not cur.has_key(d):
			cur[d] = {}
			ans += 1
		cur = cur[d]
	return ans

for t in xrange(tc):
	[n, m] = map(int, fin.readline().split(" "))
	dirs = {}
	dirs[""] = dirs
	for i in xrange(n):
		seq = fin.readline().strip('\n').split("/")
		go(dirs, seq)
	ans = 0
	for j in xrange(m):
		seq = fin.readline().strip('\n').split("/")
		ans += go(dirs, seq)
	print "Case #%(cn)d: %(ans)d" % {'cn' : t+1, 'ans' : ans}
