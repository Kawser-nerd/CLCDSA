N=int(input())
A=list(map(int,input().split(' ')))
B=list(map(int,input().split(' ')))
candy=[]
candy.append(A[0]+sum(B))
for i in range(N-1):
  candy.append(candy[-1]-B[i]+A[i+1])
print(max(candy))