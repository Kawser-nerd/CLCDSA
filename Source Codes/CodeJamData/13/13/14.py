import random

t = raw_input()

n_sets, n, m, k = map(int,raw_input().split())

print 'Case #1:'

possibilities = []
probabilities = []
n_samples = 100000
for i in range(n_samples):
	p = [random.randint(2,m) for i in range(n)]
	p.sort()
	if p in possibilities:
		probabilities[possibilities.index(p)] += 1.0/n_samples
	else:
		possibilities.append(p)
		probabilities.append(1.0/n_samples)

def prob_hit(p,r):
	if not p:
		if r == 1:
			return 1.0
		else:
			return 0.0
	prob = 0.5*prob_hit(p[1:],r)
	if r % p[0] == 0:
		prob += 0.5*prob_hit(p[1:], r/p[0])
	return prob

#print zip(probabilities,possibilities)
	
for i in range(n_sets):
	set = map(int,raw_input().split())
	best = possibilities[0]
	best_prob = 0
	for p in range(len(possibilities)):
		prob = probabilities[p]
		for s in set:
			prob *= prob_hit(possibilities[p], s) 
		if prob > best_prob:
			best_prob = prob
			best = possibilities[p]
	print ''.join(map(str,best))