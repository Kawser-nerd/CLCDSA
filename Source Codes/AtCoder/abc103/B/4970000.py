def rot(s):
  ret = s[-1]+s[:-1]
  return ret

s1=input()
s2=input()

tmp=s1
flag=False

for i in range(len(s1)):
  tmp=rot(tmp)
  if tmp == s2:
    flag=True
    
if flag:
  print('Yes')
else:
  print('No')