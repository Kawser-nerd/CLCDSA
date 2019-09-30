import sys, math

def f(x):
	if FF[x] == 0:
		FF[x] = math.factorial(x)
	return FF[x]

def cc(n, k):
	if n<k:
		return 0
	return f(n) / (f(k) * f(n-k))

def allsolve(n):
	r = 0
	for d in range(1,n):
		r += solve(d, n)
	return r

def solve(d, n):
	if d < 3:
		return 1
	if (d,n) in C:
		return C[(d,n)]
	r = 0
	for ni in range(1, d):
		freePos = d - ni - 1
		freeDigits = n - d - 1
		mul = cc(freeDigits, freePos)
#		print "-> %d %d %d %d" % (ni, freePos, freeDigits, mul)
		r = (r + solve(ni, d)*mul) % 100003
#	c[d] = r
#	print "%d, %d = %d" % (d, n, r)
	C[(d, n)] = r
	return r

C = dict()
FF = [0]*500
#print solve(3, 7)
T=int(sys.stdin.readline())
for case in range(T):
	n = int(sys.stdin.readline())
	r = allsolve(n) % 100003
	print "Case #%d: %s" % (case+1, r)
