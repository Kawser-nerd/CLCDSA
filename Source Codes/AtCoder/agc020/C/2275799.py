n = int(input())
a = [int(i) for i in input().split()]
dp = 1
for i in range(0, len(a)):
	dp = (dp | (dp << a[i]))

asum = 0
for i in range(0, len(a)):
	asum += a[i]

for i in range(int((asum + 1) / 2), asum + 1):
	if (dp >> i) & 1:
		print(i)
		break