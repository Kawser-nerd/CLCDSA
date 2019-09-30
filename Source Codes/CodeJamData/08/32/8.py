#!/usr/bin/env python

def solve():
	digits = raw_input()
	numDigits = len(digits)

	def numbers(start):
		if start == numDigits:
			assert False
		s = {}
		s[int(digits[start : ])] = 1
		for i in range(start + 1, numDigits):
			first = int(digits[start : i])
			for n, f in numbers(i).iteritems():
				s[first + n] = s.get(first + n, 0) + f
				s[first - n] = s.get(first - n, 0) + f
		return s
	return sum(
		f
		for n, f in numbers(0).iteritems()
		if n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0
		)

for case in range(int(raw_input())):
	print 'Case #%d: %s' % (case + 1, solve())
