import sys
import string
import math

def getline():
	return sys.stdin.readline()[:-1]
def exactroot(m, n):
	t = (int)(m ** (1.0 / (0.0+n)))
	while (t+1)**n <= m:
		t+= 1
	return t
countprime = []
def init():
	prime = []
	for i in range(1000072):
		prime.append(1)
	prime[0] = 0
	prime[1] = 0
	for i in range(1072):
		if prime[i] == 0:
			continue
		for j in range(i*i, 1000072, i):
			prime[j] = 0
	countprime.append(0)
	for i in range(1, 1000072):
		countprime.append(countprime[-1] + prime[i])
def testcase():
	n = int(getline())
	if n == 1:
		return 0
	output = 1
	for i in range(2, int(math.log(n)*3)):
		t = exactroot(n, i)
		#print t, countprime[t]
		if t == 1:
			break
		output += countprime[t]
	return output


init()
n = int(getline())
for i in range(n):
	print 'Case #{0}: {1}'.format(i+1, testcase())
