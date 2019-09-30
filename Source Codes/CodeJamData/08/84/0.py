import sys
from Numeric import *
input = sys.stdin

MOD = 30031

def pow(M, N, NN):
	if N==0:
		return identity(NN)
	if N==1:
		return M
	half = N/2
	hp = pow(M, half, NN)
	if N%2==0:
		return dot(hp, hp)%MOD
	else:
		return dot(dot(hp, hp)%MOD, M)%MOD

def solve(input):
	line = input.readline().split(' ')
	N = int(line[0])
	K = int(line[1])
	P = int(line[2])
	entr = []
	backw = {}
	for i in range(1<<P):
		cnt = 0
		for j in range(P):
			if ((i&(1<<j))!=0):
				cnt+= 1
		if cnt==K and (i&1)==1:
			backw[i] = len(entr)
			entr.append(i)
	NN = len(entr)
	M = zeros((NN,NN), 'O')
	for i in range(NN):
		if (entr[i]&(1<<(P-1)))!=0:
			next = entr[i] - (1<<(P-1))
			next <<= 1
			next += 1
			M[backw[next],i] += 1
		else:
			for j in range(P):
				if ((entr[i]&(1<<j))!=0) :
					next = entr[i] - (1<<j)
					next <<= 1
					next += 1
					M[backw[next],i] += 1
	M = pow(M, N-K, NN)
	v = zeros((NN))
	v[0] = 1
	vv = dot(M, v)
	return str(vv[0]%MOD)

N = int(input.readline())

for i in range(N):
	res = solve(input)
	print 'Case #'+str(i+1)+': '+res

