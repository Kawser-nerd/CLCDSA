n = int(input())
if n==3: print(2,3,25)
elif n<15003:
	print(3,9,end=" ")
	if n%3:
		for i in range(1,n-1): print(2*i,end=" ")
	else:
		print(2,4,end=" ")
		for i in range(4,n): print(2*i,end=" ")
else:
	for i in range(2,30000,2): print(i,end=" ")
	if n%2:
		for i in range(n-14999): print(6*i+3,end=" ")
	else:
		print(30000,end=" ")
		for i in range(n-15000): print(6*i+3,end=" ")