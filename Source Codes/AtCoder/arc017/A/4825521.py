n = int(input())
if n == 1:
	print("YES")
	exit()
for i in range(2,int(n**0.5)+1):
	if n%i == 0:
		print("NO")
		exit()
print("YES")