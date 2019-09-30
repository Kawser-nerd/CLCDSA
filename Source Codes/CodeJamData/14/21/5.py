def minify(s):
	r = ""
	for i in range(len(s)):
		if i==0 or s[i-1]!=s[i]:
			r += s[i]
	return r

def toarray(s):
	a = []
	for i in range(len(s)):
		if i==0 or s[i-1]!=s[i]:
			a += [1]
		else:
			a[-1] += 1
	return a
	
def solve(S):
	if len(set(minify(s) for s in S)) > 1:
		return "Fegla Won"

	A = [toarray(s) for s in S]

	ans = 0
	for p in range(len(A[0])):
		a = 99999999
		for x in range(
			min(a[p] for a in A),
			max(a[p] for a in A)+1):
			a = min(a, sum(abs(a[p]-x) for a in A))
		ans += a
	
	return ans

for i in range(input()):
	N = input()
	S = [raw_input() for _ in range(N)]
	a = solve(S)
	print "Case #%s: %s" % (i+1, a)
