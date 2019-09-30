from pulp import *
infile = open("input.txt")
outfile = open("output1.txt", "w")
Testcase = int(infile.readline())
for ti in range(Testcase):
	lp = LpProblem("GameTheoryHw", pulp.LpMinimize)
	t = infile.readline().split()
	n = int(t[0])
	V = float(t[1])
	X = float(t[2])
	r = [0] * n
	c = [0] * n
	for i in range(n):
		t = infile.readline().split()
		r[i] = float(t[0])
		c[i] = float(t[1])
	x = []
	for i in range(n):
		x.append(LpVariable("x"+str(i), 0))
	T = LpVariable("T", 0);
	lp += sum(r[i] * x[i] for i in range(n)) == V
	lp += sum(r[i] * c[i] * x[i] for i in range(n)) == V * X
	for i in range(n):
		lp += x[i] <= T
	lp += T
	lp.solve()
	ok1 = 0
	for i in range(n):
		if X > c[i]:
			ok1 = ok1 + 1
	ok2 = 0
	for i in range(n):
		if X < c[i]:
			ok2 = ok2 + 1
	if (ok1 < n and ok2 < n):
		print("Case #%d: %.10f" % (ti + 1, value(T)))
	else:
		print("Case #%d: IMPOSSIBLE"% (ti + 1)) 
