import math
temp=input().split()
n=int(temp[0])
l=int(temp[1])
t=int(temp[2])
lis = [[int(j) for j in input().split()] for i in range(n)]
cou=0
for i in range(n):
	if lis[i][1]==1:lis[i][0] += t
	else:lis[i][0] -= t
	cou += math.floor(lis[i][0] / l)

li = []
for i in range(n):li.append(lis[i][0] % l)
li.sort()
for i in range(n):
	print(li[(i + cou) % n] % l)