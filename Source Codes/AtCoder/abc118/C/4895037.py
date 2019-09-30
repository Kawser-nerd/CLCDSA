n=int(input())
a=list(map(int,input().split()))
ans=a[0]
for i in a[1:]:
	if ans > i:
		ans,i=i,ans
	while i%ans!=0:
		i,ans=ans,i%ans
	if ans ==1:
		print(1)
		break
else:
	print(ans)