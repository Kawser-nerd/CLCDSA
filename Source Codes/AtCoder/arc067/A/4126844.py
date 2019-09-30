n = int(input())
query = [0]*1001
mod = 10**9+7
tmp = n
for tmp in range(1,n+1):
 for i in range(2,1002):
  while tmp%i == 0:
   query[i-1] += 1
   tmp = tmp//i
ans = 1
for i in query:
  ans= ans*(1+i)%mod
print(ans%mod)