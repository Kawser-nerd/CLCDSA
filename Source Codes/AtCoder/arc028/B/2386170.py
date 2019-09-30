from heapq import heappushpop
n,k = (int(i) for i in input().split())
x = [int(i) for i in input().split()]
a = []
for i in range(k): a.append([-x[i],i+1])
a.sort()
print(a[0][1])
for i in range(k,n):
	heappushpop(a,[-x[i],i+1])
	print(a[0][1])