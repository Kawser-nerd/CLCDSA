n = int(input())
m = 10**10
s = 0
for i in range(n):
	a, b = map(int, input().split())
	s += a
	if a > b:
		m = min(m, b)
if m == 10**10:
	print(0)
else:
	print(s-m)