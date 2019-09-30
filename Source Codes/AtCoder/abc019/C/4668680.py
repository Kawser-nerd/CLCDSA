n = int(input())
A = list(map(int,input().split()))
res = []
for a in A:
	while a%2 == 0:
		a //= 2
	res.append(a)
print(len(set(res)))