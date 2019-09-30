S = 0
N = int(input())
P=[]
for num in range(N):
	P.append(int(input()))

P.sort(reverse=True, key=int)
P[0] = P[0]//2

for num in range(N):
	S += P[num]

print(S)