n,k = map(int ,input().split())
r = list(map(float,input().split()))
r = sorted(r,reverse = True)
ans = 0

for i in range(k):
  ans = (ans + r[k-i-1])/2

print(ans)