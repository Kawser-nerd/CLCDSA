s=input()
t=input()
s=sorted(s)
s=''.join(s)
t=sorted(t, reverse=True)
t=''.join(t)
if s<t:
  print('Yes')
else:
  print('No')