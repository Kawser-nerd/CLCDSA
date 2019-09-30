from bisect import *

def is_fairsqrt(s):
	s2 = str(int(s)**2)
	return s == s[::-1] and s2 == s2[::-1]

fairsqrts = ["", "0", "1", "2", "3"]

for sz in range(2, 52):
	for a in ["1", "2", "3"]:
		adds = []
		for base in fairsqrts:
			if(len(base) % 2 != sz % 2): continue
			
			zeros = "0" * ((sz - len(base) - 2) / 2)
			new = a + zeros + base + zeros + a
			
			if is_fairsqrt(new): adds.append(new)
		for add in adds:
			fairsqrts.append(add)

fairsqrts.remove("")

fairsquares = [int(x)**2 for x in fairsqrts]
fairsquares.sort()

T = int(raw_input())

for i in range(T):
	A, B = [int(x) for x in raw_input().split(" ")]
	a = bisect_left(fairsquares, A)
	b = bisect_right(fairsquares, B)
	print "Case #" + str(i + 1) + ": " + str(b - a)