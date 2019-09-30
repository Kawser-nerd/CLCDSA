from sys import setrecursionlimit
setrecursionlimit(100000)
n = int(input())
x,q = [[] for i in range(n)],[-1]*n
for i in range(n-1):
	a = int(input())-1
	x[a].append(i+1)
def f(z):
	y = []
	if x[z]:
		for i in x[z]:
			if q[i]+1: y.append(q(i))
			else: y.append(f(i))
		y = sorted(y)[::-1]
		for i in range(len(y)): y[i]+=i+1
		q[z] = max(y)
		return max(y)
	else:
		q[z] = 0
		return 0
print(f(0))