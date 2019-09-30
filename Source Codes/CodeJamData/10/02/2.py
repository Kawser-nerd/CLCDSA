from fractions import gcd
import sys
casenum = 0
CASES = 0
times=[]

for line in sys.stdin:
	if casenum == 0:
		CASES = int(line.strip())
	else:
		nums = [int(j) for j in line.strip().split(' ')]
		N = nums[0]
		T = abs(nums[2]-nums[1])
		for i in range (3,N+1):
			T = gcd(T,abs(nums[i]-nums[i-1]))
		print "Case #%d: %d" % (casenum, (T-(nums[1]%T))%T)
	casenum += 1
	if casenum == CASES+1:
		break
