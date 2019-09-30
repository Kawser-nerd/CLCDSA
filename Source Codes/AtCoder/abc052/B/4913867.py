n=int(input())
max_x=0
x=0
for i in input():
	if i=='I':
		x+=1
	else:
		x-=1
	max_x=max(max_x,x)
print(max_x)