import sys

L = 0
P = [1, 4, 9]

def check(s):
	r = s[::-1]
	if (L&1) == 0:
		a = int(s + r)
	else:
		a = int(s[:-1]+r)
	s2 = str(a*a)
	if s2 == s2[::-1]:
		P.append(s2)

def go(s, l, two):
	if l == 0:
		check(s)
		return
	go(s+'0', l-1, two)
	go(s+'1', l-1, two)
	if two > 0:
		go(s+'2', l-1, two-1)

for L in range(2,51):
	hf = L - (L>>1)
	go('1', hf-1, 1)
	go('2', hf-1, 0)
	print >> sys.stderr, "L = ", L

for x in P:
	print x
