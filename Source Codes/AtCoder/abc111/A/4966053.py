s=input()
s2=''
for i in range(3):
  if s[i]=='1':
    s2+='9'
  else:
    s2+='1'
print(s2)