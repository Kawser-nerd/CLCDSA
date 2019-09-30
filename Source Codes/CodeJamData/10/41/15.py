import sys, operator, string
from math import ceil, log

def choose(n,k):
	return reduce(lambda a,b: a*(n-b)/(b+1),xrange(k),1)

def PurgeZeros (TMZ):
	L = len(TMZ)
	i = 0
	while (i < L) and (TMZ[i] == 0):
		i = i + 1
	return TMZ[i:]
	
def Minus (A,B):	# A - B as if they were decimal numbers
	Base = 10
	Lab = len(A)
	if Lab != len(B): return [-1]
	C = []
	r = 0
	for i in range (1,Lab+1):
		C = [A[-i] - B[-i] - r] + C
		if C[0] < 0:
			C[0] = C[0] + Base
			r = 1
		else: r = 0
	if r > 0: return [-1]
	return PurgeZeros(C)

def Find (Vek,Ele):
	for i in range (len(Vek)):
		if Vek[i] == Ele:
			return i
	return -1

def Insert (Wort, n, s):
	if n not in Wort:
		Wort[n] = s

def InputLineS():
	StrLineS = sys.stdin.readline()
	StrLine = StrLineS.strip(' ')
	L = [StrLine]
	LN = []
	n = 1
	i = Find (StrLine,' ')
	while i >= 0:
		L[n-1:] = [StrLine[:i], StrLine[i+1:]]
		StrLine = StrLine[i+1:]
		n = n+1
		i = Find (StrLine,' ')
	for Str in L:
		LN.append(int(Str))
	return LN

def SortNumList (Biglist):
	L = len(Biglist)
	if L == 0: return []
	EL = [Biglist[0]]
	for i in range(1,L):
		A = Biglist[i]
		j = i/2
		p = i/2+1
		while ((j>0)or(A>EL[0])) and ((j<i)or(A<EL[i-1])) and ((A<EL[j-1])or(A>EL[j])):
			if p>2: p = p/2+1
			else: p = 1
			if (j < i) and (A > EL[j]):
				j = j + p
				if j > i: j = i
			else:
				j = j - p
				if j < 0: j = 0
		EL = EL[:j] + [A] + EL[j:]
	return EL

def Hex2Binlist(H):
	L = []
	x = int(H,16)
	L.append((x//8)*2-1)
	x = x-8*(x//8)
	L.append((x//4)*2-1)
	x = x-4*(x//4)
	L.append((x//2)*2-1)
	x = x-2*(x//2)
	L.append(x*2-1)
	return L

def SymmHor (D,k):
	for H in range (k):
		OK = True
		for r in range (H+1,2*k-H-2):
			a = D[r]
			b = a[:]
			b.reverse()
			La = len(a)-H
#			if H==6:
#				print La//2, r, a, b
			if (a[H:H+La//2] != b[:La//2]) & (a[:La//2] != b[H:H+La//2]):
#				if H==6:
#					print a[H:H+La//2], b[:La//2], a[:La//2], b[H:H+(La//2)]
				OK = False
				break
		if OK: return H

#def SymmVert (D,k):
#	return SymmHor (D,k)

#MAIN FUNCTION
#T = 0
T = input()
for XX in range(1,T+1):
	k = input()
	D = []
	D2 = []
	for i in range (2*k-1):
		D2.append([])
	for i in range (2*k-1):
		Line = InputLineS()
		LL = len(Line)
		D.append (Line)
		i = 0
		for r in range (k-LL,k+LL,2):
			D2[r].append(Line[i])
			i = i + 1
			
	Hor = SymmHor (D,k)
#	print "Hor =",Hor
	Vert = SymmHor (D2,k)
#	print "Vert =",Vert
#	if Vert==5: print D2
	
	Y = (k+Hor+Vert)**2 - k**2
	Str = "Case #" + str(XX) + ":"
	print Str, Y
	sys.stdout.flush()
