from re import *
from sys import stderr
def readint():
	return int(raw_input())
def readfloat():
	return float(raw_input())
def readarray(N, foo=raw_input):
	return [foo() for i in xrange(N)]
def readlinearray(foo=int):
	return map(foo, raw_input().split())

case_number = readint()
for case in xrange(case_number):
	N, K = readlinearray()
	print "Case #%d: %s" % (case + 1, (K+1) % 2**N and "OFF" or "ON")
