from __future__ import division
import sys
import math
from collections import deque
import itertools

sys.stdin = open('large.in')
sys.stdout = open('large.out', 'w')

def sequences(integers):
	integers = sorted(integers)

	def sequences_rec(ints):
		if len(ints) == 1:
			yield ints
		else:
			for s in sequences_rec(ints[1:]):
				yield ints[:1] + s
				yield s + ints[:1]

	return sequences_rec(integers)

def swaps(before, after):
	before = before[:]
	n = 0
	for i, value in enumerate(after):
		while True:
			i2 = before.index(value)
			if i2 == i:
				break

			before[i2-1], before[i2] = before[i2], before[i2-1]
			n += 1

	return n



def solve_bad(integers):
	return min(
		swaps(result, integers)
		for result in sequences(integers)
	)

def solve(integers):
	start = 0
	end = len(integers)
	swaps = 0

	while start != end:
		# print integers
		m = min(integers[start:end])
		mi = integers.index(m)

		to_start = mi - start
		to_end = end - mi - 1
		if to_start <= to_end:
			integers = integers[:start] + [m] + integers[start:mi] + integers[mi+1:]
			start += 1
			swaps += to_start
		else:
			integers = integers[:mi] + integers[mi+1:end] + [m] + integers[end:]
			end -= 1
			swaps += to_end

	return swaps


t = int(raw_input())

for i in range(t):
	n = int(raw_input())
	integers = map(int, raw_input().split())
	assert len(integers) == n
	print "Case #{}: {}".format(i+1, solve(integers))
