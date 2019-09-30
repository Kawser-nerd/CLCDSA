#!/usr/bin/env python
# Python 2.6.1
# input from stdin, output to stdout

def debug(**a):
	print " ".join("%s=%s" % (k,v) for (k,v) in a.iteritems())

def read_ints():
	return [int(x) for x in raw_input().strip().split()]

def gcd2(a,b):
	if a < b:
		return gcd2(b,a)
	elif b==0:
		return a
	else:
		return gcd2(b,a % b)

def main():
	[C]=read_ints()
	for c in xrange(1,C+1):
		t=read_ints()[1:]
		# find y such that each ti+y is divisible by T for each ti in t for the largest possible T
		# gcd(t0+y, t1+y, ..., tn+y) = T
		# T = gcd(abs(t0-t1), abs(t0-t2), ..., abs(t1-t2), ...)
		T=abs(t[0]-t[1])
		for i in xrange(len(t)):
			for j in xrange(i+1,len(t)):
				T=gcd2(T,abs(t[i]-t[j]))
		# t0+y % T = 0
		# y = -t0 % T
		y=-t[0]%T
		print "Case #%d: %d" % (c,y)

if __name__=='__main__':
	main()