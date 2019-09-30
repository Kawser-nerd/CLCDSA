S = input()
ans = float('inf')
for i in range(len(S)-1):
  if S[i] != S[i+1]:
    k = max(i+1,len(S)-i-1)
    if k <= ans:
      ans = k
if ans != float('inf'):
  print(ans)
else:
  print(len(S))