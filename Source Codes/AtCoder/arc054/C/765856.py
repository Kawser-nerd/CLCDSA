def printmat(matrix):
	for x in matrix:
		print([int(y) for y in x])
	print()

def det(matrix):
	N = len(matrix)
	a = 1

	for i in range(N):
		if matrix[i][i] == 0:
			index = [k for k in range(i+1,N) if matrix[k][i] != 0]
			if len(index) == 0:
				return 0
			else:
				k = index[0]
				a *= -1
				matrix[i], matrix[k] = matrix[k], matrix[i]

		for j in range(i+1,N):
			buf = matrix[j][i] / matrix[i][i]
			for k in range(N):
				matrix[j][k] = (matrix[j][k] - matrix[i][k] * buf) % 2
	res = 1
	for i in range(N):
		res *= matrix[i][i]

	return a*res


n = int(input())
m = [input() for _ in range(n)]
m = [[int(j) for j in i] for i in m]
print("Even" if det(m)==0 else "Odd")