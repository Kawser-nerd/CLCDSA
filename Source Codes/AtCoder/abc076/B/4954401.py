n = int(input())
k = int(input())
denko = 1

for i in range(n):
	if denko*2 <= denko+k:
		denko = denko*2
	else:
		denko += k
print(denko)