n = int(input())
if n == 1:
	print("Not Prime")
	exit()
if n%2 != 0 and n%5 != 0 and n%3 != 0:
	print("Prime")
else: 
	for i in range(2,int(n**0.5+1)):
		if n%i == 0:
			print("Not Prime")
			exit()
	print("Prime")