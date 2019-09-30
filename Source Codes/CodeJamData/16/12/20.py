#!/usr/bin/env python
import itertools

def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		N = int(raw_input())
		s = set()
		for _ in xrange(2 * N - 1):
			a = map(int, raw_input().split())
			s ^= set(a)
		print ' '.join(map(str, sorted(s)))
		assert len(s) == N

if __name__ == '__main__':
	main()
