def func(n):
	digits = [int(c) for c in str(n)]
    
	sum = 0
	for digit in digits:
		sum += digit
    
	return sum

N = int(input())

start = 0
if N-9*18 > 0:
	start = N-9*18

anss = []
for x in range(start, N+1):
	if x < 1:
		continue
	if x + func(x) == N:
		anss.append(x)

print(len(anss))
for ans in anss:
	print(ans)