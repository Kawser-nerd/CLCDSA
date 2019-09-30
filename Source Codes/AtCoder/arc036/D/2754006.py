import sys

sys.setrecursionlimit(10**8)

def find(x):	#x?????
	global table

	if table[x] == x:
		return x
	else:
		table[x] = find(table[x])	#????(???????????????)
		return table[x]

def union(x,y):	#x?y????
	x = find(x)	
	y = find(y)
	
	if x == y:
		return
	
	if rank[x] > rank[y]:
		table[y] = x
	else:
		table[x] = y
		if rank[x] == rank[y]:
			rank[y] += 1

def check(x,y): #x?y????????
	if find(x) == find(y):
		return True
	else:
		return False

N,Q = map(int,input().split())

table = [i for i in range(2*N)]	#??? table[x] == x ???	
rank  = [1 for i in range(2*N)]	#????


for i in range(Q):
	w,a,b,z = (map(int,input().split()))
	a -= 1
	b -= 1
	if w == 1:
		if z % 2 == 1:
			union(a,b+N)
			union(a+N,b)
		else:
			union(a,b)
			union(a+N,b+N)
	else:
		if check(a,b):
			print('YES')
		else:
			print('NO')