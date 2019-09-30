from math import sqrt
import sys
sys.setrecursionlimit(10**6)
def f(b, n):
	if n < b:
		return n
	else:
		return f(b, n // b) + n % b

n = int(input())
s = int(input())

if n < s:
	print(-1)
elif n == s:
	print(n+1)
else:
	divs = []
	for i in range(1, int(sqrt(n-s))+1):
		if (n-s)%i == 0:
			divs.append(i)
			if i != (n-s)//i:
				divs.append((n-s)//i)
	divs.sort()
	for d in divs:
		if f(d+1, n) == s:
			print(d+1)
			break
	else:
		print(-1)