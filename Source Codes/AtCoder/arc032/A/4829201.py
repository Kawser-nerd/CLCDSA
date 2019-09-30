n = int(input())
m = n*(n+1)//2
if n == 1:
	print("BOWWOW")
	exit()
for i in range(2,int(m**0.5)+1):
	if m%i == 0:
		print("BOWWOW")
		exit()
print("WANWAN")