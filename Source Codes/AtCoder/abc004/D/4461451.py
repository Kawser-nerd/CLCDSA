R, G, B = map(int, input().split())

def unique_cost(le, gt):
	return abs(gt * (gt - 1) // 2 - le * (le - 1) // 2)

def cost(x, shift, X):
	x -= shift
	return unique_cost(max(0, x), max(1, x+X)) + unique_cost(min(0, x), min(1, x+X))

INF = 10000
def argmin(le, gt, func):
	while gt - le > 2:
		c1 = (2 * le + gt) // 3
		c2 = (le + 2 * gt) // 3
		c1_value = func(c1)
		c2_value = func(c2)
		if c1_value > c2_value:
			le = c1
		else:
			gt = c2
	
	min_value = func(le)
	min_arg = le
	for i in range(1, gt - le):
		value = func(le + i)
		if value < min_value:
			min_value = value
			min_arg = le + i
	return min_arg

def func(g):
	g_value = cost(g, 0, G)
	r = argmin(-INF, g-R+1, lambda r: cost(r, -100, R))
	r_value = cost(r, -100, R)
	b = argmin(g+G, INF, lambda b: cost(b, 100, B))
	b_value = cost(b, 100, B)
	return g_value + r_value + b_value

print(func(argmin(-INF, INF, func)))