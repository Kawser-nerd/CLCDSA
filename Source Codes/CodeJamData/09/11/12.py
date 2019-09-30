#!/usr/bin/python
# python 2.6.1
# input from stdin, output to stdout

import sys

def read_int():
	return int(raw_input().strip())

def read_ints():
	return [int(x) for x in raw_input().strip().split()]

HAPPY={}

def sq_sum_digs(n,b):
	s=0
	while n!=0:
		a=(n%b)
		n=n//b
		s+=a*a
	return s

def happy(n,b):
#	print "happy(%d,%d)" % (n,b)
	if (n,b) in HAPPY:
		return HAPPY[(n,b)]
	if n==1:
		rv=True
	else:
		HAPPY[(n,b)]=False # catch recursion such as happy(5,3)
		rv=happy(sq_sum_digs(n,b),b)
	HAPPY[(n,b)]=rv
	return rv

def main():
	t=read_int()
	for i in range(t):
		bases=read_ints()
#		print bases
		k=2
		while True:
			ok=True
			for b in bases:
				if not happy(k,b):
					ok=False
					break
			if ok:
				print "Case #%d: %d" % (i+1,k)
				break
			k+=1
				
if __name__=="__main__":
	main()