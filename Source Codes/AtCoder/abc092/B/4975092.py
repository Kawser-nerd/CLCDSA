N=int(input())
D,X=map(int,input().split())
for i in range(N):
  X+=(D-1)//int(input())
print(X+N)