#! /Library/Frameworks/Python.framework/Versions/Current/bin/python

T = int(raw_input())

def gcd(a,b):
	r = a % b
	if r == 0:
		return b
	else:
		return gcd(b,r)

def p2(x):
	if x == 0:
		return 1
	else:
		return 2*p2(x - 1)

for t in range(T):
	inpArr = raw_input().strip().split('/')
	P = int(inpArr[0])
	Q = int(inpArr[1])

	g = gcd(P,Q)

	P /= g
	Q /= g

	if (P*p2(40)) % Q == 0:
		gen = 0
		while P < Q:
			gen += 1
			P *= 2
		print ("Case #" + str(t + 1) + ": " + str(gen))
	else:
		print ("Case #" + str(t + 1) + ": impossible")