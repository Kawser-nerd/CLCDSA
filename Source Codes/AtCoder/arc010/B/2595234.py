def dc(m,d):
	mon = [31,29,31,30,31,30,31,31,30,31,30]
	return sum(mon[:m-1])+d
n = int(input())
x = []
for _ in range(n):
	m,d = (int(i) for i in input().split("/"))
	x.append(dc(m,d))
x,y = sorted(x),[0 for i in range(368)]
for i in range(1,366,7): y[i] = 1
for i in range(7,365,7): y[i] = 1
for i in x:
	if y[i]==0: y[i]=1
	else:
		num = i+1
		while num<367:
			if y[num]==0:
				y[num] = 1
				break
			else: num+=1
ans,num = 0,0
for i in y:
	if i==1: num += 1
	else: num,ans = 0,max(ans,num)
print(ans)