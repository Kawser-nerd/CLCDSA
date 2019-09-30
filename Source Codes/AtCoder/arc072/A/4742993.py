n = int(input())
a = list(map(int, input().split()))

ans1 = 0
s1 = 0
for i in range(n):
	s1 += a[i]
	if i % 2 == 0:
		if s1 <= 0:
			ans1 += 1 - s1
			s1 = 1
	else:
		if s1 >= 0:
			ans1 += s1 + 1
			s1 = -1

ans2 = 0
s2 = 0
for i in range(n):
	s2 += a[i]
	if i % 2 == 1:
		if s2 <= 0:
			ans2 += 1 - s2
			s2 = 1
	else:
		if s2 >= 0:
			ans2 += s2 + 1
			s2 = -1

print(min(ans1, ans2))