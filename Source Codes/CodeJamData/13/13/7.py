import random

dummy = int(raw_input())

R, N, M, K = [int(i) for i in raw_input().split()]

def gen_rand_set(sz, m):
	s = []
	for i in xrange(sz):
		s.append(random.randint(2, m))
	return s

def get_rand_prod(s):
	prod = 1
	for i in xrange(len(s)):
		if random.randint(0, 1) == 1:
			prod *= s[i]
	return prod

def gen_freq(s):
	freq = {}
	for i in s:
		if i in freq:
			freq[i] += 1
		else:
			freq[i] = 1
	return freq

def get_score(s, K, freq):
	avg_score = 0
	TIMES = 100
	for i in xrange(TIMES):
		new_prods = []
		for j in xrange(K):
			new_prods.append(get_rand_prod(s))
		new_prods.sort()
		new_freq = gen_freq(new_prods)
		score = 0
		keys = set(freq.keys() + new_freq.keys())
		for k in keys:
			a = freq.get(k, 0)
			b = new_freq.get(k, 0)
			score += (a-b)**2
		avg_score += score
	return avg_score / float(TIMES)

def try_all_sets(cur, N, M, K, freq):
	if len(cur) != N:
		min_score = -1
		min_s = None
		for i in xrange(2, M+1):
			s, score = try_all_sets(cur+[i], N, M, K, freq)
			if min_score == -1 or score < min_score:
				min_score = score
				min_s = s
		return (min_s, score)
	
	return (cur, get_score(cur, K, freq))


print "Case #1:"
for Z in xrange(1, R+1):
	prods = [int(i) for i in raw_input().split()]
	freq = gen_freq(prods)

	print ''.join([str(i) for i in try_all_sets([], N, M, K, freq)[0]])

