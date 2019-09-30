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

def NOD(a, b):
	if b==0:
		return a
	else:
		return NOD(b, a%b)

case_number = readint()
for case in xrange(case_number):
	t = map(int, raw_input().split()[1:])
	b = [abs(t[0] - a) for a in t[1:]]
	res = reduce(NOD, b)
	print "Case #%s: %s" % (case + 1, res - (t[0] % res or res))
