ints = input().split(" ")
N = int(ints[0])
maxW = int(ints[1])
ints = input().split(" ")
a = int(ints[0])
b = int(ints[1])
weight = [a, a+1, a+2, a+3] 
va = [[b],[],[],[]]
for i in range(1, N):
	ins = input().split(" ")
	w = int(ins[0])
	v = int(ins[1])
	for j in range(0, 4):
		if w == weight[j]:
			va[j].append(v)
for i in range(0, len(va)):
	va[i].sort(reverse=True)
	va[i].insert(0,0)
#print(va)
sum = [[0],[0],[0],[0]]
for j in range(0, 4):
	for i in range(1, len(va[j])):
		try:
			sum[j].append(sum[j][i-1] + va[j][i])
		except:
			pass
ans = 0
#print(sum)
for i in range(0, len(va[0])):
	for j in range(0, len(va[1])):
		for k in range(0, len(va[2])):
			for l in range(0, len(va[3])):
				sumw = weight[0]*i + weight[1]*j +weight[2]*k + weight[3]*l
				if(sumw <= maxW):
					ans = max(sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l],ans)
print(ans)