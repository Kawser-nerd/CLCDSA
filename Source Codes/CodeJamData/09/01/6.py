#!/usr/bin/env python

import sys

data = [x.strip() for x in open(sys.argv[1]).readlines()]

L, D, N = map(int, data[0].split())

def tokenize(string):
	chars = []
	
	while string:
		while string and string[0] == '(':
			a, b, c = string[1:].partition(')')
			chars.append(a)
			string = c
		
		while string and string[0] != '(':
			chars.append(string[0])
			string = string[1:]
	
	return chars
	
words = data[1:D+1]

tests = data[D+1:]

def match(word, tok):
	"tests if a word matches a parsed string, returns 1 if matched"
	
	if len(word) != len(tok):
		return 0 # this should never happen though
	
	for x in range(len(word)):
		if word[x] not in tok[x]:
			return 0
	
	return 1

for t in range(len(tests)):
	tok = tokenize(tests[t])
	
	matches = sum([match(w, tok) for w in words])
	
	print "Case #%d: %d" % (t + 1, matches)
