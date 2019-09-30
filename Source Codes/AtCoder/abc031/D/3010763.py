from itertools import product
k,n = (int(i) for i in input().split())
x = [[i for i in input().split()] for i in range(n)]
for i in range(n):
	y = []
	for j in x[i][0]: y.append(int(j))
	x[i][0] = y
def match(q):
	ans = True
	for i,j in x:
		num = 0
		for i2 in i: num+=q[i2-1]
		if len(j)!=num:
			ans = False
			break
	return ans
def match2(q):
	if match(q):
		w = ["" for i in range(k)]
		for i,j in x:
			num = 0
			for i2 in i:
				if w[i2-1]=="" or w[i2-1]==j[num:num+q[i2-1]]:
					w[i2-1] = j[num:num+q[i2-1]]
					num+=q[i2-1]
				else:
					w = []
					break
		return w
	else: return False
for i in product(range(1,4),repeat=k):
	m = match2(i)
	if m:
		for j in m: print(j)
		break