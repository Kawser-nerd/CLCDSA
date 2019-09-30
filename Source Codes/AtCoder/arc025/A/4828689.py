D = list(map(int,input().split()))
J = list(map(int,input().split()))
res = 0
for i in range(7):
	if D[i] >= J[i]:
		res += D[i]
	else:
		res += J[i]
print(res)