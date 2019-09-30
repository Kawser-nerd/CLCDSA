import sys
n = int(input())
a = list(map(int, input().split()))
ans = []
Ma = 0
iMa = -1
for i in range(n):
	if abs(a[i]) > Ma:
		Ma = abs(a[i])
		iMa = i
if Ma == 0:
	print(0)
	sys.exit()
for i in range(n):
	if a[i] * a[iMa] < 0:
		a[i] += a[iMa]
		ans.append([iMa+1, i+1])
if a[iMa] > 0:
	for i in range(n-1):
		if a[i] > a[i+1]:
			a[i+1] += a[i]
			ans.append([i+1, i+2])
else:
	for i in range(n-1, 0, -1):
		if a[i-1] > a[i]:
			a[i-1] += a[i]
			ans.append([i+1, i])

print(len(ans))
for an in ans:
	print(*an)