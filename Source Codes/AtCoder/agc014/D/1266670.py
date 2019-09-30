N = list(map(int,input().split()))[0]
lis = [[] for i in range(N)]

for a_i,b_i in [ map(int,input().split()) for _ in range(N-1) ]:
	lis[a_i-1].append(b_i-1)
	lis[b_i-1].append(a_i-1)

while True:

	sumsum = 0
	for x in lis:
		sumsum += sum(x)
	if sumsum == 0:
		print("Second")
		quit()

	for i in range(len(lis)):

		if len(lis[i]) == 1:
			b = lis[i][0]
			lis[i].remove(b)
			lis[b].remove(i)
			for c in lis[b]:
				lis[c].remove(b)
				if len(lis[c]) == 0:
					print("First")
					quit()
			lis[b] = []