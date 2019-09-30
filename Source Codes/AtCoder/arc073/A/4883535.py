N,T = map(int,input().split())
X = list(map(int,input().split()))

ans = 0
for i in range(N):
 if(i != N-1):
  if(X[i]<X[i+1]<X[i]+T): ans += X[i+1] - X[i]
  else: ans += T
 elif(i == N-1):
  ans += T
print(ans)