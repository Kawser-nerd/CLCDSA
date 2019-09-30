a,b,c=map(int,input().split())
if a+b==c:
  print('Yes')
elif a+c==b:
  print('Yes')
elif b+c==a:
  print('Yes')
else:
  print('No')