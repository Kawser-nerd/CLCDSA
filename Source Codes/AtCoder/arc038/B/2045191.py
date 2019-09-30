H,W = map(int,input().split())
S = [input() for i in range(H)]

memo = [[None for j in range(W)] for i in range(H)]

def dfs(y,x):
	global memo
	if x >= W or y >= H or S[y][x] == '#':
		return True
	if memo[y][x] is not None:
		return memo[y][x]

	res = False
	if not dfs(y + 1,x):
		res = True
	if not dfs(y+1,x+1):
		res = True
	if not dfs(y,x + 1):
		res = True
	memo[y][x] = res
	return res

print("First" if dfs(0,0) == True else "Second")