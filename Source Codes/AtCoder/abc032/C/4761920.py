N, K=list(map(int, input().split()))
S = [int(input()) for _ in range(N)]

if 0 in S:
  print(N)
  exit()

j=0

answer = 0
s=1
for i in range(0,N):
  if i>=1:
    s=s//S[i-1]
  if j<=i:
    s=S[i]
    j=i
    if s>K:
      continue
  while j<=N-2:
    if s*S[j+1]<=K:
      s=s*S[j+1]
      j+=1
    else:
      break
  #print(i,j,S[i:j+1], s)
  answer = max(answer ,j-i+1)
print(answer)