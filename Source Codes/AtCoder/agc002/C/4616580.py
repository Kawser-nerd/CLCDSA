N, L = list(map(int, input().split()))
a = list(map(int, input().split()))

judge = "Impossible"
for i in range(N - 1):
	x = a[i] + a[i + 1]
	if x >= L:
		judge = "Possible"
		c = i + 1
		break


if judge == "Impossible":
	print(judge)
else:
	print(judge)
	for i in range(1, c):
		print(i)
	for i in range(N - c - 1):
		print(N - 1 - i)
	print(c)