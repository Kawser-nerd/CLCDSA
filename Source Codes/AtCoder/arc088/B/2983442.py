S=list(input())

K=(len(S)+1)//2

if len(S)%2==0:
  mark=S[len(S)//2]
  if mark!=S[len(S)//2-1]:
    print(K)
    exit()
  count=1
  while(0<len(S)-K-count):
    if mark!=S[len(S)//2-1-count] or mark!=S[len(S)//2+count]:
      print(K+count)
      exit()
    count+=1
  print(K+count)
else:
  mark=S[len(S)//2]
  count=0
  while(0<len(S)-K-count):
    if mark!=S[len(S)//2-1-count] or mark!=S[len(S)//2+1+count]:
      print(K+count)
      exit()
    count+=1
  print(K+count)