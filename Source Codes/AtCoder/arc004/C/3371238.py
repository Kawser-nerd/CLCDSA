x,y = (int(i) for i in input().split("/"))
f,n = 0,2*x//y
for i in [n,n+1]:
	if i and i*x%y==0: print(i,i*(i+1)//2-i*x//y)
	else: f+=1
if f==2: print("Impossible")