#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys

def main():
	f = sys.stdin
	
	cases = int(f.readline())
	for case in range(1, cases+1):
		tmp = [ int(x) for x in f.readline().strip().split(' ') ]
		n = tmp[0]
		m = tmp[1]
		x = tmp[2]
		y = tmp[3]
		z = tmp[4]
		
		A = []
		for i in range(m):
			A.append(int(f.readline().strip()))
		
		signs = []
		for i in range(n):
			signs.append( A[i % m] )
			A[i % m] = (int(x * A[i % m]) + int(y * (i+1))) % z

		result = 0
		total = len(signs)
		i = total - 1
		count = {}
		sum_count = 0
		while i>=0:
			j = i+1
			i_count = 0
			while j<total:
				if signs[i] < signs[j]:
					i_count = i_count + 1 + count[j] 
				j = j+1
			count[i] = i_count
			sum_count = sum_count + i_count
			i = i-1
		sum_count = sum_count + total
		
		result= str(sum_count % 1000000007)
		print "Case #%(case)d: %(result)s" % locals()
	pass
	
if __name__ == '__main__':
	sys.exit(main())


