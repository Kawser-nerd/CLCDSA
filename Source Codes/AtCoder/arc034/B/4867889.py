import numpy as np

def func(n):
	digits = [int(c) for c in str(n)]
    
	sum = 0
	for digit in digits:
		sum += digit
	
	return sum

N = int(input())

anss = []
for x in range(N-9*(int(np.log10(N))+1), N+1):
	if x < 1:
		continue
	if x + func(x) == N:
		anss.append(x)

print(len(anss))
for ans in anss:
	print(ans)