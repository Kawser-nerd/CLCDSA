N, K = map(int, input().split())
R = [int(i) for i in input().split()]
R.sort()
Rate = 0

for i in R[N-K: N+1]:
  Rate = (Rate + i) / 2
  
print(Rate)