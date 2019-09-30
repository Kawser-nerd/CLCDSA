#!/usr/bin/python

import sys, pdb

#f = open("b.in", "r")
f = sys.stdin

n = int(f.readline().strip())


a = []
s = ""
ans = ""
found = False
counts = []
used = []

def bt(pos, greater):
	global a, ans, found, used
	if found: return
	if pos == len(s):
		if greater:
			found = True
			ans = "".join(a)
		return
	if greater:
		i = 0
		while used[i] == counts[i]:
			i += 1
		used[i] += 1
		a[pos] = str(i)
		bt(pos + 1, greater)
		used[i] -= 1
	else:
		i = int(s[pos])
		used[i] += 1
		a[pos] = str(i)
		bt(pos + 1, False)
		used[i] -= 1
		i += 1
		while i < 10 and used[i] == counts[i]:
			i += 1
		if i < 10:
			used[i] += 1
			a[pos] = str(i)
			bt(pos + 1, True)
			used[i] -= 1

for test in xrange(n):
	s = f.readline().strip()
	a = ["" for i in xrange(len(s))]
	counts = [0] * 10
	used = [0] * 10
	for c in s:
		counts[int(c)] += 1
	found = False
	#pdb.set_trace()
	bt(0, False)
	if not found:
		i = 1
		while counts[i] == 0: i += 1
		result = str(i)
		counts[i] -= 1
		counts[0] += 1
		i = 0
		while i < 10:
			while counts[i]:
				result += str(i)
				counts[i] -= 1
			i += 1
		ans = result
	print "Case #%d: %s" % (test + 1, ans)
