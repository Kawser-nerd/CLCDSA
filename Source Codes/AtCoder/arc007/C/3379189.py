from itertools import product
s = input()
n = len(s)
x,y,ans = [[] for i in range(n)],[],n
for i in range(n):
	if s[i]=="o": y.append(i)
for i in range(n):
	for j in y: x[i].append((j+i)%n)
def f(q):
	p = [0]*n
	for i in range(n):
		if q[i]:
			for j in x[i]: p[j] = 1
	if sum(p)-n: return 0
	else: return sum(q) 
for i in product([0,1],repeat=n):
	if f(i): ans = min(ans,f(i))
print(ans)