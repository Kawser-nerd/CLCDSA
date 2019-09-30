N=int(input())
a=[int(input()) for _ in range(N)]
b=list(sorted(list(set(a))))
dic={}
for i in range(len(b)):
	dic[b[i]]=i
for i in range(N):
	print(dic[a[i]])