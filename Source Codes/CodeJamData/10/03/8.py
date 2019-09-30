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
	R,k,N = readlinearray()
	g = readlinearray()
	if (sum(g) <= k):
		res = sum(g)*R
	else:
		g += g
		costs = [(0,0)] * (N+10)
		cur = 0
		while not costs[cur][0]:
			next = cur
			while sum(g[cur:next]) <= k:
				next += 1
			next -= 1
			costs[cur] = (sum(g[cur:next]), next % N)
			cur = next % N
		cycle_start = cur
		price = 0
		cur = 0
		while cur != cycle_start:
			price += costs[cur][0]
			R -= 1
			cur = costs[cur][1]
		cycle_price, cycle_length = costs[cur][0], 1
		cur = costs[cur][1]
		while cur != cycle_start:
			cycle_price += costs[cur][0]
			cycle_length += 1
			cur = costs[cur][1]
		price += R/cycle_length * cycle_price
		R %= cycle_length
		while R:
			price += costs[cur][0]
			R -= 1
			cur = costs[cur][1]
		res = price
	print "Case #%s: %s" % (case + 1, res)
