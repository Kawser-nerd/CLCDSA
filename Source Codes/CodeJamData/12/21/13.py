from sys import stdout
def fill(si, tot):
	for j in xrange(len(si) - 1):
		if si[j] < si[j + 1]:
			diff = min(tot, (si[j + 1] - si[j])*(j + 1))
			si[j] += float(diff) / (j + 1)
			tot -= diff
			for k in xrange(0, j):
				s[k] = s[j]
			if tot <= 0.0:
				break
	diff = float(tot) / len(si)
	for k in xrange(0, len(si)):
		si[k] += diff

def solve(si):
	ans = []
	tot = sum(si)
	xi = [(s, j) for j, s in enumerate(si)]
	xi.sort()
	si.sort()
	#print 'si', si
	fill(si, tot)
	#print 'si', si
	#tot = sum(x[0] for x in xi)
	si = [(xi[j][1], float(si[j] - xi[j][0])/tot) for j in xrange(len(si))]
	si.sort()
	si = [s[1] for s in si]
	return si

t = int(raw_input())
for case in xrange(1, t + 1):
	s = [int(x) for x in raw_input().split()][1:]
	s = solve(s)
	stdout.write("Case #%d:" % case)
	#print 'sum', sum(s)
	for a in s:
		stdout.write(" %.10f" % (a * 100.0))
	stdout.write("\n")

