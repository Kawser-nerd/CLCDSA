N,K = map(int,input().split())
ans = 0
if K != 0:
  for b in range(1,N+1):
    p = N//b
    ans += max(0,(b-K)*p)+max((N%b)-K+1,0)
else:
  ans = N**2
print(ans)