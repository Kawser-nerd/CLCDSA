#!/usr/bin/env python

import sys

def mark_chars(c, line):
	def test(char):
		if char == c:
			return 1
		return 0
	return [test(x) for x in line]

def rollup(ch):
	"rollup([1,2,3,4]) = [1,3,6,10]"
	for x in range(1, len(ch)):
		ch[x] = ch[x] + ch[x-1]
	
	return ch

def replace(ch, rep):
	"replace([1,0,0,0,1,1], [1,2,3,4,5,6]) -> [1,0,0,0,5,6]; operates in place"
	for x in range(len(ch)):
		if ch[x] == 1:
			ch[x] = rep[x]

def count_subs(phrase, line):
	prev = rollup(mark_chars(phrase[0], line))
	for c in phrase[1:]:
#		print prev
		m = mark_chars(c, line)
		replace(m, prev)
		prev = rollup(m)
#	print prev
	
	return prev[-1]
	
#print count_subs('abcd', 'aca bbcdc')

phrase = "welcome to code jam"

data = [x.strip() for x in open(sys.argv[1]).readlines()[1:]]

n = 1
for line in data:
	print "Case #%d: %04d" % (n, count_subs(phrase, line) % 10000)
	n = n + 1
