import sys

def mkd(need, have):
	if need in have or len(need) == 0:
		return 0
	slash = need.rindex('/')
	parent = need[:slash]
	r = mkd(parent, have)
	have.add(need)
	return r + 1
	
def hv(have, him):
	if len(him) < 2:
		return
	have.add(him)
	slash = him.rindex('/')
	parent = him[:slash]
	hv(have, parent)

T=int(sys.stdin.readline())
for case in range(T):
	have = set()
	have.add('/')
	N, M = map(int, sys.stdin.readline().split())
	r = 0
	for i in range(N):
		hv(have, sys.stdin.readline().rstrip())
	for i in range(M):
		need = sys.stdin.readline().rstrip()
		r += mkd(need, have)
		
	print "Case #%d: %d" % (case+1, r)