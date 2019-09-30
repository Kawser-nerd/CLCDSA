def dp_table(*counts):
	return [dp_table(*counts[1:]) for _ in range(counts[0])] if counts else None

A, B = map(int, input().split())

# DP?????????????

# x: ?????
# d: ??????????????
# less: ??????
# forbidden: ????????
def solve(dp, x, d=0, less=False, forbidden=False):
	if len(x) <= d:
		return forbidden
	if dp[d][less][forbidden] is not None:
		return dp[d][less][forbidden]

	res = 0
	for i in range(10 if less else x[d]+1):
		# determine d-th digit (as i), and if it is less and/or forbidden
		res += solve(dp, x, d+1, less or i < x[d], forbidden or i == 4 or i == 9)
	dp[d][less][forbidden] = res
	return res

def count(n):
	N = list(map(int, str(n)))
	return solve(dp_table(20, 2, 2), N)

print(count(B) - count(A-1))