#!/usr/bin/env python
def best_score(score):
	return (score + 2) / 3

def best_surprise_score(score):
	if score < 2:
		return score
	return (score + 4) / 3

def benefit_from_surprise(score, p):
	return best_score(score) < p and best_surprise_score(score) >= p

def process_file(file):
	fsock = open(file)
	text = fsock.read()
	fsock.close()
	lines = text.split('\n')
	return lines

def process_lines(lines):
	ans = []
	first = True
	for line in lines:
		if first == True:
			first = False
		else:
			if line != '':
				case = {}
				N = -1
				S = -1
				p = -1
				t = []
				for num in line.split(' '):
					if N == -1:
						N = int(num)
					elif S == -1:
						S = int(num)
					elif p == -1:
						p = int(num)
					else:
						t.append(int(num))
				case['N'] = N
				case['S'] = S
				case['p'] = p
				case['t'] = t
				ans.append(case)
	return ans

def process_case(line):
	N = line['N']
	S = line['S']
	p = line['p']
	t = line['t']
	good = 0
	maybe = 0
	for score in t:
		if best_score(score) >= p:
			good += 1
		elif maybe < S and benefit_from_surprise(score, p):
			maybe += 1
	good += min(maybe, S)
	return good

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))