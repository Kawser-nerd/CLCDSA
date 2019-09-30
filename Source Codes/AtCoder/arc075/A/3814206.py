N = int(input())
nap = [1]
X = [0 for i in range(10000)]
nap.extend(X)

for i in range(N):
	s = int(input())
	for j in range(1,10002):
		if nap[-j] == 1:
			nap[-j + s] = 1

ans = 0
for i in range(10001):
	if nap[i] == 1:
		if i % 10 != 0:
			ans = i

print(ans)