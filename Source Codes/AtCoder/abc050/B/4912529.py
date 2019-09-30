n=int(input())
q=list(map(int,input().split()))
m=int(input())
for i in range(m):
	clist=q
	num,t=map(int,input().split())
	print(sum(clist)-clist[num-1]+t)