import sys


N = int(raw_input())

def process():
	P, K, L = [int(x) for x in raw_input().split()]
	probs = [int(x) for x in raw_input().split()]

	probs.sort(reverse = True)
	p = 1
	k = 0
	ret = 0
	for x in probs:
		k += 1
		if k > K:
			k = 1
			p += 1
	
		ret += p * x

	return ret

		

for case in range(0, N):
	print 'Case #%i:'%(case+1), process()

