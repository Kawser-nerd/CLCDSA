def one_test():
	n = int(input())
	g = list(int(s) - 1 for s in input().split())
	cycle = [-1] * n
	for i in range(n):
		if cycle[i] == -1:
			seen = set()
			v = i
			while v not in seen:
				seen.add(v)
				v = g[v]
			if v == i:
				length = len(seen)
				while g[v] != i:
					cycle[v] = length
					v = g[v]

	#print(cycle)

	max_in = [0] * n
	ugly = set(range(n)) - set(g)
	for v in ugly:
		i, cur = v, 0
		while cycle[i] == -1:
			max_in[i] = max(max_in[i], cur)
			cur += 1
			i = g[i]
		max_in[i] = max(max_in[i], cur)

	ans = max(cycle)
	ans_2 = 0
	for v in range(n):
		if cycle[v] == 2 and g[v] > v:
			ans_2 += max_in[v] + max_in[g[v]] + 2
			#ans = max(ans, max_in[v] + max_in[g[v]] + 2)
	return max(ans, ans_2)

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
