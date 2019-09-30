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

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		line = f.readline()
		S, K = line.split(' ')
		S = list(S)
		K = int(K)
		ret = 0
		for j in xrange(len(S) - K + 1):
			if S[j] == '-':	#flip
				for k in xrange(K):
					if S[j + k] == '-':
						S[j + k] = '+'
					else:
						S[j + k] = '-'
				ret += 1
		ret = str(ret)
		for s in S:
			if s == '-':
				ret = 'IMPOSSIBLE'
				break
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
