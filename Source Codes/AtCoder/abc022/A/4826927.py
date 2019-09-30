N,S,T = map(int,input().split())
W = int(input())
ans = 0
if S <= W <=T:
    ans += 1
for i in range(N-1):
  B = int(input())
  W+=B
  if W>=S and W<=T:
    ans+=1
print(ans)