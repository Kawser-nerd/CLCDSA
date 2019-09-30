import itertools
import bisect 
import numpy as np

def main_1():
	if n == 1:
		if goods[0][1] <= w:
			print(goods[0][0])
			return
		else:
			print(0)
			return

	left = goods[:int(n/2)]
	right = goods[int(n/2):]

	left_comb = all_comb(left)
	right_comb = all_comb(right)
	right_weight = [x[1] for x in right_comb]

	out = []
	for x in left_comb:
		if x[1] > w:
			continue
		else:
			idx = bisect.bisect_right(right_weight, w - x[1])
			#print(right_weight,idx)
			#print(x, right_comb, right_comb[idx-1])
			out.append(right_comb[idx-1][0] + x[0])

	print(max(out))
	return

def all_comb(goods):
	pts = itertools.chain(*list(itertools.combinations(range(len(goods)), i) for i in range(len(goods) + 1)))
	#print(list(pts))
	out = []
	for pt in pts:
		sum_v = 0
		sum_w = 0
		for i in range(len(goods)):
			if i in pt:
				sum_v += goods[i][0]
				sum_w += goods[i][1]
		out.append([sum_v, sum_w])

	out.sort(key = lambda x: x[1])

	i = 1
	while i < len(out):
		if out[i][0] <= out[i - 1][0]:
			out.pop(i)
		else:
			i += 1 

	return out

def main_2():
	dp = [[0 for _ in range(w + 1)] for _ in range(n + 1)]

	# i1??????i2???????????value
	for i1 in range(n + 1):
		if i1 == 0:
			continue
		for i2 in range(w + 1):
			if i2 - goods[i1][1] < 0:
				dp[i1][i2] = dp[i1 - 1][i2]
			else:
				dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1 - 1][i2 - goods[i1][1]] +  goods[i1][0])
	print(dp[n][w])

def main_2_np():
	dp = np.zeros((n+1, w+1))
	for i in range(1, n+1):
		dp[i] = dp[i - 1]
		if goods[i][1] <= w:
			dp[i][goods[i][1]:] = np.maximum(dp[i - 1][goods[i][1]:], dp[i-1][:(w - goods[i][1] + 1)] + goods[i][0])
	print(int(dp[n][w]))

def main_3():
	max_v = sum([x[0] for x in goods])
	dp = [[np.inf for _ in range(max_v + 1)] for _ in range(n + 1)]

	dp[0][0] = 0
	# i1????value i2??????????weight
	for i1 in range(n + 1):
		if i1 == 0:
			continue
		for i2 in range(max_v + 1):
			if i2 - goods[i1][0] < 0:
				dp[i1][i2] = dp[i1 - 1][i2]
			else:
				dp[i1][i2] = min(dp[i1 - 1][i2], dp[i1 - 1][i2 - goods[i1][0]] + goods[i1][1])
	ans = 0
	for i in range(len(dp[n])):
		if dp[n][i] <= w:
			ans = i

	print(ans)

def main_3_np():
	max_v = sum([x[0] for x in goods])
	dp = np.full((n+1, max_v+1), np.inf)

	dp[0][0] = 0
	for i in range(1, n+1):
		dp[i] = dp[i - 1]
		if goods[i][0] <= max_v:
			dp[i][goods[i][0]:] = np.minimum(dp[i - 1][goods[i][0]:], dp[i-1][:(max_v - goods[i][0] + 1)] + goods[i][1])

	ans = 0
	for i in range(len(dp[n])):
		if dp[n][i] <= w:
			ans = i
	print(ans)

if __name__ == '__main__':
	n, w = list(map(int, input().split()))
	goods = [[0, 0]]
	goods.extend([list(map(int, input().split())) for _ in range(n)])
	#print(goods)

	if n <= 30:
		main_1()
	elif max([x[1] for x in goods]) <= 1000:
		main_2_np()
	else:
		main_3_np()