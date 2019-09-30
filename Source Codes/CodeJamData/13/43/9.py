import sys

cases = sys.stdin.readline()
N = None
B = None
A = None
RR = None

def copy(a):
	return [x for x in a]

def solve(sepA, sepB, n):

		if n==N+1:
			return True

		compA = [0 for i in range(0, N)]	
		mA = 1
		for i in range(0,N):
			mA = max(mA, sepA[i] + 1)
			compA[i] = mA
		compB = [0 for i in range(0, N)]	
		mB = 1
		for i in xrange(N-1,-1,-1):
			mB = max(mB, sepB[i] + 1)
			compB[i] = mB			
		for i in range(0,N):			
			if A[i]==compA[i] and B[i]==compB[i]:
				pr = RR[i]
				pa = sepA[i]
				pb = sepB[i]				
				RR[i] = n
				sepA[i] = compA[i]
				sepB[i] = compB[i]
				rr = copy(RR)
				if solve(copy(sepA), copy(sepB), n+1):
					return True
				for j in range(0, N): RR[j] = rr[j]
				RR[i] = pr
				sepA[i] = pa
				sepB[i] = pb
		return False


for case in range(0,int(cases)):	
	N = int(sys.stdin.readline())
	A = [int(x) for x in sys.stdin.readline().split()]
	B = [int(x) for x in sys.stdin.readline().split()]
	RR = [0 for i in range(0, N)]
	sepA = [0 for i in range(0, N)]
	sepB = [0 for i in range(0, N)]	
	solve(sepA, sepB, 1)	

	print "Case #%d:" % (case+1),
	for i in range(0, len(RR)): 
		if i==len(RR)-1: print RR[i]
		else: print RR[i],
