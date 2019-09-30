n, a, b, c = list(map(int, input().split()))
ls = [int(input()) for _ in range(n)]

min_ans = 10 ** 10
for i in range(4 ** n):
	mm = [[], [], [],[]]
	tmp = i
	for i2 in range(n):
		g = tmp // (4 ** (n - i2 - 1))
		tmp = tmp % (4 ** (n - i2 - 1))
		mm[g%4].append(ls[i2])
	
	if len(mm[0]) * len(mm[1]) * len(mm[2]) == 0:
		continue

	#print(mm)
	ans = abs(sum(mm[0]) - a) + abs(sum(mm[1]) - b) + abs(sum(mm[2]) - c) + (len(mm[0]) - 1) * 10 + (len(mm[1]) - 1) * 10 + (len(mm[2]) - 1) * 10
	min_ans = min(ans, min_ans)

print(min_ans)