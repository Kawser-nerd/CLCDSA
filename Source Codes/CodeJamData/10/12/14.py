#!/usr/bin/env python
# Python 2.6.x plus (possibly) the following non-standard libraries
#   numpy -- http://numpy.scipy.org/
#   scipy -- http://www.scipy.org/
# input from stdin, output to stdout   -- or --  progname.py input output  -- or --  progname.py input

import os
import sys

def debug(*x,**a):
	print "DEBUG: %s" % " ".join([repr(v) for v in x]+["%s=%s" % (k,repr(v)) for (k,v) in a.iteritems()])
	sys.stdout.flush()
	
def read_ints():
	return [int(x) for x in raw_input().strip().split()]

def main():
	[N_CASES]=read_ints()
	for case in xrange(1,N_CASES+1):
		[D,I,M,N] = read_ints()
		A=read_ints()
		minA=min(A)
		A=[x-minA for x in A]
		Z=max(A)+1
#		debug(D=D,I=I,M=M,A=A)
		def insertions(a,b):
			if abs(a-b)<=M:
				return 0
			if M==0:
				return 1000000
			return (abs(a-b)-1)//M*I
		# c[i,j] = min cost to smooth a[0:i] such that the last element of the smoothed array has value j
		# c[0,j] = 0
		# c[i+1,j] : if A[i] is in j+-M, then min()
		c=[0]*Z
		for a in A:
			cc=[0]*Z
			for j in xrange(Z):
				cost=c[j]+D 
				for k in xrange(Z):
					# go from c[k] to c[j]
					if j==a:
						cost=min(cost,c[k]+insertions(k,a)) # insert stuff to get to a
					else:
						# we have to insert to get from k to a, and then from a to j, plus insert j
						cost=min(cost,c[k]+insertions(k,a)+insertions(a,j)+I)
						# or change a to j and get from k to j
						cost=min(cost,c[k]+abs(j-a)+insertions(k,j))
				cc[j]=cost
			c=cc
		print "Case #%d: %d" % (case,min(c))

### run main

if __name__=='__main__':
	main()
