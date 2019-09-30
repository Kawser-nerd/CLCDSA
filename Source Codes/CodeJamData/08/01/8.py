#!/usr/bin/env python

import sys
lines = sys.stdin.readlines()

N = lines.pop(0)
for case_iterator in range(int(N)):

	engine_names = []
	S = lines.pop(0)
	for engine_iterator in range(int(S)):
		engine_names.append(lines.pop(0))

	query = []
	Q = lines.pop(0)
	for query_iterator in range(int(Q)):
		query.append(lines.pop(0))

	#greedy algorithm:

	current_engine = None
	current_position = 0
	num_of_switches = -1 #will not count the first choice

	while current_position < len(query):
		next_length = {}
		for engine in engine_names:
			if engine != current_engine:
				position = current_position
				while position < len(query) and query[position] != engine:
					position = position + 1
				next_length[engine] = position - current_position

		max_length = 0
		for engine in engine_names:
			if engine != current_engine and next_length[engine] > max_length:
				max_length = next_length[engine]
				switch_to = engine

		current_engine = switch_to

		current_position = current_position + max_length
		num_of_switches = num_of_switches + 1

	if int(Q)==0:
		num_of_switches = 0	
	print "Case #"+str(case_iterator+1)+": "+str(num_of_switches)
