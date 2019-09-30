S = list(str(input()))
n = len(S)

diff = 0
for i in range(n//2):
	if S[i] != S[-i-1]:
		diff += 1

res = n * 25
if diff == 0:
	if n % 2 == 1:
		res -= 25
elif diff == 1:
	res -= 2

print(res)