def check(n, a):
	cnt=0
	b=[0]*1010
	f=[0]*1010
	len=[0]*1010
	for i in range(1,n+1):
		j=0
		for k in range(1,cnt+1):
			if (b[k]+1==a[i]) and (j==0 or len[k]<len[j]):
				j=k
		if j==0:
			cnt+=1
			j=cnt
		b[j]=a[i]
		len[j]+=1
	ans=100000000
	for i in range(1,cnt+1):
		ans = min(ans, len[i])
	return ans

for c in range(input()):
	a=map(int,raw_input().split())
	n=a[0]
	a=a[1:]
	b=[0]
	a.sort();
	b.extend(a)
	ans=check(n, b)
	if ans == 100000000:
		ans = 0
	print "Case #"+str(c+1)+": "+str(ans)

