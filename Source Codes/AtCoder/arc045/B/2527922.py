n,m = (int(i) for i in input().split())
s = [[int(i) for i in input().split()] for i in range(m)]
x,y,ans = [0 for i in range(n+2)],[],[]
for i,j in s: x[i],x[j+1] = x[i]+1,x[j+1]-1
for i in range(1,n+2):
	x[i] += x[i-1]
	if x[i]==1: y.append(i)
from bisect import bisect
from bisect import bisect_left
for i in range(m):
	if bisect_left(y,s[i][0])==bisect(y,s[i][1]): ans.append(i+1)
print(len(ans))
for i in ans: print(i)