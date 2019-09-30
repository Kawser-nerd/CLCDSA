x = 0
ans = 10**10
for i in map(int, list(input())):
	x = (x * 10) % 1000 + i
	ans = min(abs(x-753), ans)
print(ans)