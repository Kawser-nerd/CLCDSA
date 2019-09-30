def YesNo(f):
	return ["Yes", "No"][not(f)]

A, B = map(int, input().split())
print(YesNo(A*B%2!=0))