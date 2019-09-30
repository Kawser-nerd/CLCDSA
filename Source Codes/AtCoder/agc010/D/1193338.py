import random
def tester(N=0):
	'''??
1?N?105
1?Ai?109
'''
	maxno1=1e5
	maxno2=1e9
	s=input()
	if s!='':return(s)
	
	if N==0:
		return(random.randint(2,maxno1))
	else:
		print('Testing...')
		print('N=',N)
		A=[]
		for i in range(N):
			A.extend([random.randint(1,maxno2)])
		return(' '.join(list(map(str,A))))

import copy

def gcd(a, b):
	while b:
		a, b = b, a % b
	return a

def gcdm(x):
	g=x[0]
	for i in range(1,len(x)):
		if g==1:
			return(g)
		g=gcd(g,x[i])
	return(g)

def playmove(A,i):
	A[i]-=1
	g=gcdm(A)
	return([x//g for x in A])

def noofevens(A):
	r=0
	for i in A:
		if i%2==0:
			r+=1
	return(r)
			

N=int(tester())
A=[int(x) for x in tester(N).split()]


isFirstmove=True
while True:
	e=noofevens(A)
	if e%2==1:
		if isFirstmove:
			print('First')
		else:
			print('Second')
		break
	elif N-e>1:
		if isFirstmove:
			print('Second')
		else:
			print('First')
		break
	else:	
		for i in range(N):
			if A[i]%2==1:
				break
		if A[i]==1:
			if isFirstmove:
				print('Second')
			else:
				print('First')
			break
		else:
			A=playmove(A,i)
			isFirstmove=(isFirstmove!=True)