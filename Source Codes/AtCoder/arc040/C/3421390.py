N = int(input())
lines = [input() for i in range(N)]
count = 0;y = -1;flag=False
while y < N-1:
	y += 1
	x = N
	while x > 0:
		x -= 1
		if (lines[y][x] == '.'):
			count += 1
			if y+1<=N-1: y += 1
			else: flag = True;break
	if flag: break
print(count)