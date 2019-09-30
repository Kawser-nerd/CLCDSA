N=int(input())
X=list(map(int,input().split(' ')))
Y=sorted(X)
for i in range(N):
  print(Y[N//2-1]) if X[i]>Y[N//2-1] else print(Y[N//2])