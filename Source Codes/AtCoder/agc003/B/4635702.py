N = int(input())
ans = 0
c = 0
for i in range(N):
	A = int(input())
	ans += int((A + c) // 2)
	if A >= 2 and (A + c) % 2 != 0:
		c = 1
	else:
		c = 0

print(ans)