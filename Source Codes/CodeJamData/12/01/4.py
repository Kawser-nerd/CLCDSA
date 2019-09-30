#!/usr/bin/env python
dictionary = {
	'a': 'y',
	'b': 'h', 
	'c': 'e',
	'd': 's',
	'e': 'o',
	'f': 'c',
	'g': 'v',
	'h': 'x',
	'i': 'd',
	'j': 'u',
	'k': 'i',
	'l': 'g',
	'm': 'l',
	'n': 'b',
	'o': 'k',
	'p': 'r',
	'q': 'z',
	'r': 't',
	's': 'n',
	't': 'w',
	'u': 'j',
	'v': 'p',
	'w': 'f',
	'x': 'm',
	'y': 'a',
	'z': 'q'
	}

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
			trans = ''
			for char in line:
				if char in dictionary:
					trans += dictionary[char]
				else:
					trans += char
			if trans != '':
				ans.append(trans)
	return ans

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	res = process_lines(lines)
	c = 0
	for line in res:
		c += 1
		print "Case #%d: %s" % (c, line) 