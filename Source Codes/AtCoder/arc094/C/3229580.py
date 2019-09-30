n = int(input())
m,num = 10**9+1,0
for _ in range(n):
	a,b = (int(i) for i in input().split())
	num+=a
	if a>b and m>b: m = b
if m==10**9+1: print(0)
else:  print(num-m)