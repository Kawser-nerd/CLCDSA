
def win(n,k):
	return all(n[i] > k[i] for i in xrange(len(n)))

def solve():
	N = int(raw_input())
	naomi = map(float, raw_input().split())
	ken = map(float, raw_input().split())

	naomi.sort()
	ken.sort()

	nc,kc = naomi[:], ken[:]
	deceitful_score = 0
	while not win(nc, kc):
		del kc[-1]
		del nc[0]

	print len(nc),

	war_score = 0
	for n in naomi:
		final = 0
		for idx, k in enumerate(ken):
			if k > n:
				final = idx
				break

		if n > ken[final]: war_score += 1
		del ken[final]

	print war_score


T = int(raw_input())

for t in xrange(T):
	print "Case #%d:" % (t+1),
	solve()