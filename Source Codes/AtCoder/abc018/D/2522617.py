from itertools import combinations

N,M,P,Q,R = map(int,input().split(" "))
dic = { i: [] for i in range(1,(N+1)) for j in range(1,(M+1))}
for i in range(R):
	x,y,z = map(int,input().split(" "))
	dic[x].append((y,z))

ans = -float('inf')
for com in combinations(range(1,N+1),P):
	boys = [0]*M
	for n in com:
		for b in dic[n]:
			boys[b[0]-1] += b[1]
	boys.sort(reverse=True)
	ans = max(ans,sum(boys[:Q]))

print(ans)