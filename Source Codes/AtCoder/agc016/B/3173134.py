from collections import Counter
n = int(input())
a = [int(i) for i in input().split()]
a.sort()
c = Counter(a)
if len(c)>2 or a[0]+1<a[-1]: print("No")
elif len(c)==1:
	if a[0]+1==n or n>=2*a[0]: print("Yes")
	else: print("No")
else:
	x,y = c[a[-1]],c[a[0]]
	if y+1<=a[-1]<=x//2+y: print("Yes")
	else: print("No")