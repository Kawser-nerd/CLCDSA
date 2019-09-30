A,B=map(int,input().split())
S=input()
flag=False
for i in range(len(S)):
  if i!=A and ((ord(S[i])-ord('0'))<0 or 9<(ord(S[i])-ord('0'))):
    break
  if i==A and S[i]!='-':
    break
  
  if i==len(S)-1:
    flag=True
    
if flag:
  print('Yes')
else:
  print('No')