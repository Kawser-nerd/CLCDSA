#!/usr/bin/python2.7

def work(A,B,NL):
	res = 0
	pts = 0
	S = [0] * NL
	R2 = 0
	while True:
		cont = True
		while cont:
			cont = False
			for k in range(NL):
				if S[k]<2 and B[k]<=pts:
					cont = True
					pts += (2 - S[k])
					S[k] = 2
					res += 1
					R2 += 1
					if R2 == NL:
						return res

		# Try one.
		cont = False
		Sel = [k for k in range(NL) if S[k]==0 and A[k]<=pts]
		if len(Sel) == 0:
			return 'Too Bad'
		k = max(Sel, key = lambda i: B[i])
		pts += 1
		res += 1
		S[k] = 1

T = int(raw_input())
for k in range(1,T+1):
	NL = int(raw_input())
	A = [0] * NL
	B = [0] * NL
	for i in range(NL):
		A[i],B[i] = map(int,raw_input().split())
	print('Case #{}: {}'.format(k, work(A,B,NL)))
