N=int(input())
BLUE=[input() for i in range(N)]
M=int(input())
RED=[input() for i in range(M)]
List=list(set(list(set(BLUE))+list(set(RED))))
ans=0
for s in List:
  p=BLUE.count(s)
  m=RED.count(s)
  ans=max(ans,p-m)
print(ans)