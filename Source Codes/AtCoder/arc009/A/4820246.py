n = int(input())
res = 0
for i in range(n):
	a,b = map(int,input().split())
	res += a*b
print(int(res*1.05))