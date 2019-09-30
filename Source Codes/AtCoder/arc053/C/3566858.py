import math
n = int(input())
magic = [list(map(int, input().split())) for i in range(n)]
plus = []
minus = []
for i in magic:
	if i[0] > i[1]:
		plus.append(i)
	else:
		minus.append(i)
plus.sort(key=lambda x: x[1], reverse=True)
minus.sort(key=lambda x: x[0])
temp = 0
ans = 0
for i in minus:
	temp += i[0]
	ans = max(ans, temp)
	temp -= i[1]
for i in plus:
	temp += i[0]
	ans = max(ans, temp)
	temp -= i[1]
print(ans)