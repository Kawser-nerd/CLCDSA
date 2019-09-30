N=int(input())
ans = 0
for A in map(int, input().split()):
	while A%2 == 0:
		A //= 2
		ans += 1
print(ans)