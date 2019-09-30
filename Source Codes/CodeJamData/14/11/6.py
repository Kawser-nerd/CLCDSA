import sys
def F(s):
	re = 0
	for i in range(len(s)):
		re += (ord(s[i]) - ord('0')) << i
	return re
def C(x):
	if x == 0:
		return 0
	return x % 2 + C(x / 2)
t = input()
for tt in range(t):
	print >>sys.stderr, "???", tt
	n, l = map(int, raw_input().split())
	a = map(F, raw_input().split())
	b = map(F, raw_input().split())
	ans = 2 * l
	for i in range(n):
		for j in range(n):
			A = []
			B = []
			for k in range(n):
				A.append(a[k]^a[i])
				B.append(b[k]^b[j])
			A = sorted(A)
			B = sorted(B)
			if A == B:
				ans = min(ans, C(a[i]^b[j]))
	print "Case #%d:"%(tt + 1),
	if ans == 2 * l:
		print "NOT POSSIBLE"
	else:
		print ans