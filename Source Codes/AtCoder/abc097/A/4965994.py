a,b,c,d=map(int,input().split())
if abs(c-a)<=d:
  print('Yes')
elif abs(b-a)<=d and abs(c-b)<=d:
  print('Yes')
else:
  print('No')