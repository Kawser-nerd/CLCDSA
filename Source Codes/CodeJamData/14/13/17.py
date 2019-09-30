import random
import numpy as np
import sys
import math

def bad(n):
	xs = list(range(n))
	for i in range(n):
		p = random.randint(0, n-1)
		xs[i], xs[p] = xs[p], xs[i]
	return xs

def bad_dist(n):
	ds = np.eye(n)

	for i in range(n):
		ds_new = ds.copy()
		ds /= n
		for p in range(n):
			if i == p:
				continue

			ds_new[i] -= ds[i]
			ds_new[p] -= ds[p]

			ds_new[i] += ds[p]
			ds_new[p] += ds[i]
		ds = ds_new
	return ds


len_seq = 1000

bd = bad_dist(len_seq)
log_bd = np.log(bd)

n_cases = int(sys.stdin.readline())
for i_case in range(n_cases):
	sys.stdin.readline()
	ns = list(map(int, sys.stdin.readline().split()))
#	print(ns)

	# Use Bayes' theorem to guess prob
	# Forget p(seq) term.
	log_p_good = math.log(1 / len_seq) * len_seq + math.log(0.5)

	log_p_s_bad = 0
	for (i, n) in enumerate(ns):
		log_p_s_bad += log_bd[i][n]
	log_p_bad = log_p_s_bad + math.log(0.5)

	res = 'GOOD' if log_p_good > log_p_bad else 'BAD'

	print("Case #%d: %s" % (i_case + 1, res))
