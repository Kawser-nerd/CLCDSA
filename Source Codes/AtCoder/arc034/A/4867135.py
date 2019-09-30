N = int(input())
scores = []
for idx in range(0, N):
	scores.append(list(map(int, input().split())))

sums = []
for score in scores:
	sum = score[0] + score[1] + score[2] + score[3] + score[4]*11/90.0
	sums.append(sum)

print(max(sums))