N=int(input())
A=[0]+list(map(int,input().split(' ')))+[0]
D=[abs(A[i+1]-A[i]) for i in range(N+1)]
S=sum(D)
for i in range(N):
  print(S-abs(A[i]-A[i+1])-abs(A[i+1]-A[i+2])+abs(A[i]-A[i+2]))