n,k,q = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
ans = 10**9
for i in a:
	p,s,f = [],0,1
	for j in range(n):
		if a[j]>=i and f:
			s,f = j,0
		elif a[j]<i and f-1:
			if j-s>=k:
				for j2 in sorted(a[s:j])[:j-s-k+1]: p.append(j2)
			f = 1
	if f-1 and n-s>=k:
		for j2 in sorted(a[s:n])[:n-s-k+1]: p.append(j2)
	if len(p)>=q: ans = min(ans,sorted(p)[q-1]-i)
print(ans)