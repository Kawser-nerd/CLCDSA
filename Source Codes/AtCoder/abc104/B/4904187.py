S = input()
if(S[0]=='A' and S[2:-1].count('C') == 1):
  cnt = 0
  for i in S:
    if(not (97<=ord(i) and ord(i)<=122)):
      cnt+=1
  if(cnt==2):
    print('AC')
  else:
    print('WA')
else:
  print('WA')