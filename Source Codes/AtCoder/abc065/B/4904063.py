N=int(input())
A=[int(input())-1 for _ in range(N)]
result=[False]*N
k=0
while 1:
	newlight=A[k]
	if k==1:
		ans=0
		break
	elif result[k]:
		ans=1
		break
	else:
		result[k]=True
		k=newlight
if ans:
	print(-1)
else:print(sum(result))