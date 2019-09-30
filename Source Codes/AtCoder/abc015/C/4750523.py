import sys
sys.setrecursionlimit(10**9)

n,k = map(int,input().split())
t = [list(map(int,input().split())) for i in range(n)]

def dfs(q,x):
	if q == n:
		if x == 0:
			return True
		else:
			return False
	for i in range(k):
		if dfs(q+1,x^t[q][i]):
			return True

if dfs(0,0):
	print("Found")
else:
	print("Nothing")