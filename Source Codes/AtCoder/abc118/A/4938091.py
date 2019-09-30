i = list(map(int, input().split()))
if (i[1]%i[0])==0:
	print(i[0]+i[1])
else:
	print(i[1]-i[0])