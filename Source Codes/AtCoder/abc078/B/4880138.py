x,y,z = map(int,input().split())
ans = 0
x = x-2*z
while x-y >= 0:
	x = x-y-z
	ans +=1
print(ans)