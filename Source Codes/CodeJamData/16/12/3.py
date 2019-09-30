from collections import Counter

def one_test():
	n = int(input())
	a = []
	for i in range(2 * n - 1):
		a.extend(map(int, input().split()))
	c = Counter(a)
	ans = sorted(k for k, v in c.items() if v % 2 == 1)
	return ' '.join(map(str, ans))

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
