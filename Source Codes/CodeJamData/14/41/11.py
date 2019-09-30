#!/usr/bin/python


import sys

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		n, maxC = map(int, sys.stdin.readline().split())
		sz = map(int, sys.stdin.readline().split())
		sz.sort()
		discNeed = 0
		while len(sz) > 0:
			discNeed = discNeed + 1
			tail = sz.pop()
			if len(sz) > 0:
				if tail + sz[0] <= maxC:
					for i in reversed(range(len(sz))):
						if tail + sz[i] <= maxC:
							sz = sz[:i] + sz[i+1:]
							break
		print "Case #{}: {}".format(t+1, discNeed)
