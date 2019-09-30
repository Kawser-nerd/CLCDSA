N,T=map(int,list(input().split()))
c=1001
for i in range(N):
  ct,tc=map(int,list(input().split()))
  if T>=tc and c>=ct:
    c=ct
if c==1001:
  c="TLE"
print(c)