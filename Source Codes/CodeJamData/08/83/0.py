import sys
input = sys.stdin

MOD = 1000000009

def binom(num, fr):
	if num<=0:
		return 1
	if fr<=0:
		return 0
	prod = 1
	for i in range(num):
		prod *= fr-i
		prod = prod % MOD
	return prod

def compute(n, k, v, links, used, level):
	used[v] = True
	root = -1
	for i in links[v]:
		if used[i]:
			root = i
			level[v] = level[i]+1
	if level[v]<0:
		level[v] = 0
	colorsLeft = k
	if level[v]>=1:
		colorsLeft -= len(links[root])
	subtrees = len(links[v])
	if level[v]>=1:
		subtrees -= 1
	res = binom(subtrees, colorsLeft)%MOD
	for i in links[v]:
		if i != root:
			res = (res*compute(n, k, i, links, used, level) )% MOD
	return res

def solve(input):
	line = input.readline().split(' ')
	n = int(line[0])
	k = int(line[1])
	links = []
	for i in range(n):
		links.append([])
	for i in range(n-1):
		line = input.readline().split(' ')
		links[int(line[0])-1].append(int(line[1])-1)
		links[int(line[1])-1].append(int(line[0])-1)
	used = [False]*n
	level = [-1]*n
	res	= compute(n, k, 0, links, used, level)
	return str(res)

N = int(input.readline())

for i in range(N):
	res = solve(input)
	print 'Case #'+str(i+1)+': '+res

