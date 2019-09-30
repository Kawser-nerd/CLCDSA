#!/usr/bin/python

import sys

def find(l,e):
	for i in range(len(l)):
		if l[i] == e:
			return i

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		n = int(sys.stdin.readline())
		d = map(int, sys.stdin.readline().split())
		od = d[:]
		od.sort()
		operNeed = 0
		for elm in od:
			idx = find(d,elm)
			d.remove(elm)
			operNeed = operNeed + min(idx-0, len(d)-idx)
		print "Case #{}: {}".format(t+1, operNeed)


