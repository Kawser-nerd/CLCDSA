from pprint import pprint

T = int(raw_input().strip())

for case in range(1,T+1):

	P = int(raw_input().strip())
	constraints = map(int,raw_input().strip().split(' '))
	for i in range(P):
		prices = map(int,raw_input().strip().split(' '))

	tickets_bought = []
	for p in range(P):
		tickets_bought.append(set([]))
	for player in xrange(2**P):
		for r in xrange(P,constraints[player],-1):
			tickets_bought[r-1].add(player/(2**r))
	
	ans = sum(map(len,tickets_bought)) * prices[0]

	print "Case #%d: %d" % (case, ans)
