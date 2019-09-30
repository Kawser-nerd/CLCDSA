import sys

N = int(input())
h_li = []

for i in range(N):
	h_li.append(int(input()))
	
s = 0 #??
t = 0 #??
u = 0 #??
ans = 0
up = True	
	
for i in range(1,N):
	if up:
		if h_li[i-1] < h_li[i]:
			t = i
			u = i
		else:
			u = i
			up = False
	else:
		if h_li[i-1] > h_li[i]:
			u = i
		else:
			ans = max(ans,u-s+1)
			s = i-1
			t = i
			u = i
			up = True

ans = max(ans,u-s+1)

print (ans)