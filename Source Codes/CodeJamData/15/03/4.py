#!/usr/bin/python

import sys
import numpy as np

me = np.matrix([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]])
mi = np.matrix([[0, 1, 0, 0], [-1, 0, 0, 0], [0, 0, 0, -1], [0, 0, 1, 0]])
mj = np.matrix([[0, 0, 1, 0], [0, 0, 0, 1], [-1, 0, 0, 0], [0, -1, 0, 0]])
mk = np.matrix([[0, 0, 0, 1], [0, 0, -1, 0], [0, 1, 0, 0], [-1, 0, 0, 0]])

m = {'i':mi, 'j':mj, 'k':mk}

def solve(L,R,Seq):
	current = me
	target = [mi, mj]
	currenttarget = 0
	noprogress = 0
	for r in xrange(R):
		for s in Seq:
			if s in m:
				current = current * m[s]
				if np.array_equal(current, target[currenttarget]):
					currenttarget = currenttarget + 1
					current = me
					noprogress = 0
				if currenttarget >= len(target):
					break
		if currenttarget >= len(target):
			break
		noprogress = noprogress + 1
		if noprogress > 8:
			break
	if currenttarget < len(target):
		return False
	current = me
	for s in Seq:
		if s in m:
			current = current * m[s]
	if np.array_equal(current ** (R % 8), mi*mj*mk):
		return True
	return False

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		l,r = map(int, sys.stdin.readline().split())
		s = sys.stdin.readline()
		print "Case #{}: {}".format(t+1, 'YES' if solve(l,r,s) else 'NO')