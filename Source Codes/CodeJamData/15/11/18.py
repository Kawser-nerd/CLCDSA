def ReadIn():
	t = int(input())
	for c in range(1, t + 1):
		n = int(input())
		a = [int(x) for x in input().split()]
		yield c, a

def Solve(a):
	b = [a[i - 1] - a[i] for i in range(1, len(a))]
	m1 = sum(x for x in b if x > 0)
	rate = max(max(b), 0)
	m2 = sum(min(x, rate) for x in a[:-1]);
	return '%s %s' % (m1, m2)

if __name__ == '__main__':
	for c, a in ReadIn():
		print('Case #%d: %s' % (c, Solve(a)))