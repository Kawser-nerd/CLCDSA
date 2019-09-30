#!/usr/bin/env python
# Python 2.6.1
# input from stdin, output to stdout

def debug(**a):
	print " ".join("%s=%s" % (k,v) for (k,v) in a.iteritems())

def read_ints():
	return [int(x) for x in raw_input().strip().split()]

def main():
	[T]=read_ints()
	for t in xrange(1,T+1):
		[N,K]=read_ints()
		NN=1<<N
#		debug(N=N,K=K,NN=NN)
		if K%NN == NN-1:
			print "Case #%d: ON" % t
		else:
			print "Case #%d: OFF" % t


if __name__=='__main__':
	main()