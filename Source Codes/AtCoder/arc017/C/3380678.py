from itertools import product
from collections import defaultdict
n,x = (int(i) for i in input().split())
w = [int(input()) for i in range(n)]
def f(m):
	q = defaultdict(int)
	for i in product([0,1],repeat=m):
		num = 0
		for j in range(m): num+=w[j]*i[j]
		q[num]+=1
	return q
if n<17: print(f(n)[x])
else:
	q1,w = f(16),w[::-1]
	q2,ans = f(n-16),0
	for i,j in q1.items(): ans+=j*q2[x-i]
	print(ans)