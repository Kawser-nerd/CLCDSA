#!/usr/bin/python

import sys
import numpy as np

if len(sys.argv) != 2:
	print "usage: ./a.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

def solve(N):
	list_N = list(str(N))
	for i in xrange(len(list_N) - 1, 0, -1):
		if int(list_N[i]) < int(list_N[i - 1]):
			num_2_del = int(''.join(list_N[i:])) + 1
			return solve(N - num_2_del)
	return N

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		line = f.readline()
		N = int(line)
		ret = str(solve(N))
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
