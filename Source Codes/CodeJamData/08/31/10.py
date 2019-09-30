#!/usr/bin/env python

def solve():
	lpk, keys, alph = [ int(i) for i in raw_input().split() ]
	freq = [ int(i) for i in raw_input().split() ]
	assert len(freq) == alph
	assert lpk * keys >= alph
	freq.sort()
	freq.reverse()
	presses = 0
	for repeat, index in enumerate(range(0, lpk * keys, keys)):
		presses += sum(n for n in freq[index : index + keys]) * (repeat + 1)
	return presses

for case in range(int(raw_input())):
	print 'Case #%d: %s' % (case + 1, solve())
