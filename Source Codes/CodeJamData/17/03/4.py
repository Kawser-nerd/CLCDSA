#!/usr/bin/python

import sys
import heapq

if len(sys.argv) != 2:
	print "usage: ./a.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

def max_min_LR(N):
	if N == 0:
		return 0, 0
	elif N % 2 == 0:
		return N / 2, N / 2 - 1
	else:
		return N / 2, N / 2

def solve(N, K):
	q = [-N]
	d = {}
	d[N] = 1
	while q:
		cur = -heapq.heappop(q)
		count = d[cur]
		if K <= count:
			return max_min_LR(cur)
		K -= count
		left_space = (cur + 1) / 2 - 1
		right_space = cur - 1 - left_space
		if left_space in d:
			d[left_space] += count
		else:
			d[left_space] = count
			heapq.heappush(q, -left_space)
		if right_space in d:
			d[right_space] += count
		else:
			d[right_space] = count
			heapq.heappush(q, -right_space)
	return 0, 0

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		line = f.readline()
		N, K = [int(x) for x in line.split(' ')]
		results.append(' '.join([str(x) for x in solve(N, K)]))

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
