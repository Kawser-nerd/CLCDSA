import math

N = int(input())
n = math.ceil(math.sqrt(N))

a = 0
b = 0
for i in reversed(range(1, n+1)):
	if N%i==0:
		a = i
		b = N//i
		break

print(max(len(str(a)), len(str(b))))