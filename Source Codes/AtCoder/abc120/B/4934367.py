a, b, k = map(int, input().split())
divisor = []
for i in range(1, min(a, b)+1):
	if a % i == 0 and b % i == 0:
		divisor.append(i)
divisor.sort(reverse=True)
print(divisor[k-1])