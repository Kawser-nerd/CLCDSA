n,m=map(int,input().split())
s=input()
flag=True
if s[n:n+1]!='-':
  flag=False
for i in range(n):
  if s[i]=='-':
    flag=False
for i in range(n+1,len(s)):
  if s[i]=='-':
    flag=False
if flag:
  print('Yes')
else:
  print('No')