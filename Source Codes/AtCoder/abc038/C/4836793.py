n = int(input())
a = [int(_) for _ in input().split()]

r = 0
ans = 0

for l in range(n):
	while r < n - 1 and a[r] < a[r + 1]:
		r+=1
	ans+=r - l + 1
	if r == l:r+=1

print(ans)