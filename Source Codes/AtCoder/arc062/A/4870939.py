N=int(input())
P=[list(map(int,input().split(' '))) for i in range(N)]
T=[P[i][0] for i in range(N)]
A=[P[i][1] for i in range(N)]
t=T[0]
a=A[0]
k=1
for i in range(1,N):
	k1 = int((T[i-1]*k-1)//T[i]+1)
	k2 = int((A[i-1]*k-1)//A[i]+1)
	k = max(k1,k2)
print(k*(T[-1]+A[-1]))