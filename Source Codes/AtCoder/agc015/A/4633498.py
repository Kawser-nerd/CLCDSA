N,A,B=map(int,input().split(' '))
if (N==1 and A!=B) or A>B:
	print('0')
else:
	print(str(int((N-2)*(B-A)+1)))