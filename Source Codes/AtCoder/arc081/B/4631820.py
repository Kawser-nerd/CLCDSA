N = int(input())
S = list(input())
d = []


i = 0
while i < N - 1:
	if S[i] == S[i + 1]:
		d.append(2)
		i += 1
	else:
		d.append(1)
	i += 1

if N - 1 - i == 0:
	d.append(1)
n = len(d)

if d[0] == 1:
	dp = 3
else:
	dp = 6

for i in range(n - 1):
	if d[i] == 1:
		dp = dp * 2
	elif d[i] == 2 and d[i + 1] == 2:
		dp = dp * 3
	else:
		pass
	dp = dp % 1000000007

print(dp)