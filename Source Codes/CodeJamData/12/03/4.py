#!/usr/bin/env python
import math

def numRecycledGreater(x, ceiling, digits):
	count = 0
	power = int(math.pow(10, digits - 1))
	y = x / 10 + (x % 10) * power
	done = set()
	for i in range(digits - 1):
		if y not in done:
			if y <= ceiling and y > x:
				count += 1
			done.add(y)
		y = y / 10 + (y % 10) * power
	return count


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
				A = -1
				B = -1
				for num in line.split(' '):
					if A == -1:
						A = int(num)
					elif B == -1:
						B = int(num)
				case['A'] = A
				case['B'] = B
				ans.append(case)
	return ans

def process_case(line):
	A = line['A']
	B = line['B']
	count = 0
	digits = 0
	z = A
	while z > 0:
		z = z / 10
		digits += 1
	for x in range(A, B + 1):
		count += numRecycledGreater(x, B, digits)
	return count

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))