import collections
N=int(input())
A=list(map(int,input().split(' ')))
counter=collections.Counter(A)
ans=0
ans_part=-1
for x in sorted(list(counter.keys()))[::-1]:
	if ans_part==-1:
		if counter[x] >= 4:
			ans = x**2
			break
		elif 2<=counter[x]<=3:
			ans_part=x
	else:
		if counter[x] >= 2:
			ans=ans_part*x
			break
print(ans)