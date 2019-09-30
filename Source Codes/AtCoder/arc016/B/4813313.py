n = int(input())
l = [input() for i in range(n)]
sum = 0
for i in range(len(l)):
	for j in range(9):
		if l[i][j] == 'x':
			sum += 1
		elif l[i][j] == 'o' and (i + 1 == len(l) or l[i + 1][j] != 'o'):
			sum += 1
print(sum)