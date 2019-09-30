import sys

def gcd(a, b):
	while b != 0:
		a, b = b, a%b
	return a

input = sys.stdin.readlines()
tc = int(input[0])
for cs in range(tc):
	ls = input[cs+1].split(' ')
	n = int(ls[0])
	t = [int(x) for x in ls[1:]]

	t.sort()
	g = t[1]-t[0]
	for i in range(2, len(t)):
		g = gcd(g, t[i] - t[i-1])
	print("Case #%s: %s" % (str(cs+1), str((-t[0])%g)))


