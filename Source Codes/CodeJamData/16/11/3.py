def one_test():
	s = input()
	res = ""
	for c in s:
		res = max(c + res, res + c)
	return res

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
