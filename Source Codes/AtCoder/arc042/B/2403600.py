from math import sqrt
x,y = (int(i) for i in input().split())
n = int(input())
a = [[int(i) for i in input().split()] for i in range(n)]
ans = float("inf")
for i in range(n-1,-1,-1):
	z1 = (a[i][1]-a[i-1][1])*x+(a[i-1][0]-a[i][0])*y+a[i-1][0]*(a[i-1][1]-a[i][1])+a[i-1][1]*(a[i][0]-a[i-1][0])
	z2 = sqrt((a[i][1]-a[i-1][1])**2+(a[i-1][0]-a[i][0])**2)
	ans = min(ans,abs(z1)*1.0/z2)
print(ans)