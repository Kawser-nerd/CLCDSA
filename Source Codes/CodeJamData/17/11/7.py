fin = open("testa.in")
fout = open("testa.out", "w")

def solve():
	r, c = map(int, fin.readline().rstrip().split())
	a = [list(fin.readline().rstrip()) for i in range(r)]
	
	lstok = -1
	for i in range(r):
		st, fn = c, -1
		for j in range(c):
			if a[i][j] != '?':
				st = min(st, j)
				fn = j
		if fn != -1:
			for j in range(st):
				a[i][j] = a[i][st]
			lst = st
			for j in range(st, c):
				if a[i][j] != '?':
					lst = j
				else:
					a[i][j] = a[i][lst]
			for ii in range(lstok + 1, i):
				a[ii] = a[i]
			lstok = i
	for i in range(lstok + 1, r):
		a[i] = a[lstok]
	ans = ""
	for i in range(r):
		ans += ''.join(a[i]) + '\n'
	return ans


for test_num in range(1, int(fin.readline().rstrip()) + 1):
	print("Case #" + str(test_num) + ":\n" + solve(), end = '', file = fout)
fout.close()