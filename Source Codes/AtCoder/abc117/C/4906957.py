n,m=map(int, input().split())
if n >= m:
	print(0)
else:
	x=sorted(map(int, input().split()))
	diff=sorted([x[i]-x[i-1] for i in range(1, m)])
	print(sum(diff[:m-n]))