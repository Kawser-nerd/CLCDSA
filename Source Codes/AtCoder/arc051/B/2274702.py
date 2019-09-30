def mat_mul(a, b):
	ans = []
	for i in range(len(a)):
		ans.append([])
		for j in range(len(b[0])):
			tmp = 0
			for k in range(len(a[0])):
				tmp += a[i][k] * b[k][j]
			ans[i].append(tmp)
	return ans

n = int(input())+1
x = [[1],[0]]
y = [[1,1],[1,0]]

while n > 0:
	if (n&1) > 0:
		x = mat_mul(y,x)
	n //= 2
	y = mat_mul(y,y)

print("{} {}".format(x[0][0],x[1][0]))