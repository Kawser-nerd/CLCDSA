L,n = (int(i) for i in input().split())
x = [int(input()) for i in range(n)]
t,t2,y,a = [0],[0],[],0
for i in range(n):
	t.append(t[-1]+x[i])
	t2.append(L+t2[-1]-x[n-i-1])
	y.append(L-x[n-i-1])
for i in range(n):
	if (n-i-1)%2: a = max(a,y[(n-i-1)//2]+2*(t[i+(n-i-1)//2+1]-t[i]+t2[(n-i-1)//2]))
	else: a = max(a,2*(t[i+(n-i-1)//2+1]-t[i]+t2[(n-i-1)//2])-x[i+(n-i-1)//2])
for i in range(n):
	if (n-i-1)%2: a = max(a,x[(n-i-1)//2]+2*(t2[i+(n-i-1)//2+1]-t2[i]+t[(n-i-1)//2]))
	else: a = max(a,2*(t2[i+(n-i-1)//2+1]-t2[i]+t[(n-i-1)//2])-y[i+(n-i-1)//2])
print(a)