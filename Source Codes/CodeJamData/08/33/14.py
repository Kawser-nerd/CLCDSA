import sys
from bisect import bisect_left as bisect, insort

N = int(raw_input())

def process():
	n, m, X, Y, Z = [int(x) for x in raw_input().split()]
	A = []
	for i in range(0, m):
		A.append(int(raw_input()))
	
	L = []
	for i in range(0, n):
		L.append((A[i%m], 1))
		A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
	
	Lsort = []

	for i in range(0, len(L)):
		x = bisect(Lsort, (L[i][0], i))
		
		for k in range(0, x):
			if Lsort[k][0] == L[i][0]:
				continue
			#print 'with',i,L[i],'bisecting',k,Lsort[k]
			#L[Lsort[k][0]] = (L[Lsort[k][0]][0], L[Lsort[k][0]][1]+1)
			L[i] = (L[i][0], L[i][1] + L[Lsort[k][1]][1])
		
		insort(Lsort, (L[i][0], i))
		#print Lsort


	#print Lsort
	#print L

	ret = 0
	for x in L:
		ret += x[1] % 1000000007
	
	return ret % 1000000007



		

for case in range(0, N):
	print 'Case #%i:'%(case+1), process()

