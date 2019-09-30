N = int(input())
L = [0]*N
R = [0]*N

for i in range(N):
	L[i],R[i] = map(int,input().split(" "))
L.sort(reverse=True)
R.sort()
ans = 0
acc = 0
for i in range(N):
	ans = max(ans,acc+2*L[i])
	acc += (2*(L[i]-R[i]))
	ans = max(ans,acc)

acc = 0
for i in range(N):
	ans = max(ans,acc+2*(-R[i]))
	acc += (2*(L[i]-R[i]))
	ans = max(ans,acc)

print(ans)