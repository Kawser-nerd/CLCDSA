# Rajat Goel (Python)
import sys, itertools

fst = [1, 1]
def pre():
	global fst
	for i in xrange(2, 1000001):
		fst.append(i+1-fst[fst[i-1]])

def solve(X):
	global fst
	A1, A2, B1, B2 = (int(i) for i in raw_input().strip().split())
	
	ans = 0
	for i in xrange(A1, A2+1):
		f, l = fst[i], fst[i]+i-1
		
		if B2 < f or B1 > l:
			ans += (B2 - B1 + 1)
		else:
			if B1 >=f and B2 <=l:
				pass
			elif B1 <= f and B2 >= l:
				ans += (B2 - B1 + 1) - (l - f + 1)
			elif B1 > f:
				ans += (B2 - l)
			else:
				ans += (f - B1)

	print "Case #%d:" % (X,),ans

if __name__ == "__main__":
	pre()
	T = int(raw_input())
	for i in xrange(1, T+1):
		solve(i)
