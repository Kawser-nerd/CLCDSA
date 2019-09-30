N=int(input())
A=list(map(int, input().split()))

for y in sorted(zip(range(1,N+1), A), reverse=True, key=lambda x:x[1]):
  print(y[0])