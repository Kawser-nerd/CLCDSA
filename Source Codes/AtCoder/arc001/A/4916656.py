n = int(input())
c = list(input())
c = list(map(int, c))

maxi = -1
mini = 200

for i in range(1, 5):
	now = c.count(i)
	maxi = max([maxi, now])
	mini = min([mini, now])

print(maxi, mini)