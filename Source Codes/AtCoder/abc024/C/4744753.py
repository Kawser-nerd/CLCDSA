N,D,K = map(int,input().split())
LR = [list(map(int,input().split())) for i in range(D)]
SK = [list(map(int,input().split())) for i in range(K)]

for i in SK:
	start = i[0]
	goal = i[1]
	if start < goal:
		for j in range(D):
			l = LR[j][0]
			r = LR[j][1]
			if l<=start<=r:
				start = r
				if start >= goal:
					print(j+1)
					start,goal = 0,0
					break
	if start > goal:
		for j in range(D):
			l = LR[j][0]
			r = LR[j][1]
			if l<=start<=r:
				start = l
				if start <= goal:
					print(j+1)
					start,goal = 0,0
					break