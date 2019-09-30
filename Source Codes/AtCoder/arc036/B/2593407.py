n = int(input())
h = [int(input()) for i in range(n)]
if n!=1 and h[0]>h[1]: up = False
else: up = True
i,num,ans = 0,1,1
while i<n-1:
	if up:
		if h[i]<h[i+1]: num+=1
		else: up,num=False,num+1
	else:
		if h[i]>h[i+1]: num+=1
		else: up,num,ans = True,2,max(ans,num)
	i += 1
print(max(ans,num))