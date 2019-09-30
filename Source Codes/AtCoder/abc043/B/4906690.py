s=input()
a=''
for i in range(len(s)):
  if s[i]=='0':
    a=a+'0'
  elif s[i]=='1':
    a=a+'1'
  else:
    a=a[:-1:]
print(a)