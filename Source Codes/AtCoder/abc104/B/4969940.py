s=input()
flag=True
if s[0]!='A':
  flag=False
if 'C' not in s[2:-1]:
  flag=False
count=0
for i in range(len(s)):
  if s[i].islower():
    count+=1
if len(s)-count != 2:
  flag=False
if flag:
  print('AC')
else:
  print('WA')