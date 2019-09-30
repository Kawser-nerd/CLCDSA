N,K=map(int,input().split())
if K==0: print(N**2);exit(0)
ans=(N-K)*(N-K+1)//2
for b in range(K+1, N):
  n=(N-b+1)//b
  ans+=(n)*(b-K)
  if n*b+b-1!=N:
    if N%b>=K:
      ans+=N%b-K+1
print(ans)