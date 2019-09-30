n = int(input())
lis = list(map(int, input().split()))

key = lis[0]
num = [0]
li = [key]
for i in range(1,n):
	if lis[i] > key:
		key = lis[i]
		num.append(i)
		li.append(key)

m = len(li)
nu = [li[0]]+[li[i+1]-li[i] for i in range(m-1)]

he = [0]*m
cou = [0]*m

from bisect import bisect_left

for k in lis:
	sen = bisect_left(li,k)
	cou[sen] += k -li[sen]
	he[sen] += 1

key = 0
for i in reversed(range(m)):
	key += he[i]
	he[i] = key

for i in range(m):
	cou[i] += he[i]*nu[i]

ans = [0]*n
for i,c in zip(num,cou):
	ans[i] = c

for r in ans:
	print(r)