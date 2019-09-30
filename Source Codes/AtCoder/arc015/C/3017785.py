from fractions import Fraction

n = int(input())
edges = {}

for i in range(n):
	large, coeff, small = input().split()
	coeff = Fraction(int(coeff))
	for key in [large, small]:
		if key not in edges: edges[key] = []
	edges[small].append((large, coeff))
	edges[large].append((small, Fraction(1) / coeff))

k0 = list(edges.keys())[0]
val = {k0: Fraction(1)}

def dfs(s):
	me = val[s]
	for tg, c in edges[s]:
		if tg in val: continue
		val[tg] = me * c
		dfs(tg)

dfs(k0)

tmp = [(val[x], x) for x in val]
mxname = max(tmp)[1]
mnname = min(tmp)[1]

print('1'+mxname+'='+str((val[mxname]/val[mnname]).numerator)+mnname)