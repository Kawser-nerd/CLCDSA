a=int(input())
b=int(input())
c=int(input())
mx=max(a,b,c)
mn=min(a,b,c)
if a==mx:
  print(1)
elif a==mn:
  print(3)
else:
  print(2)

if b==mx:
  print(1)
elif b==mn:
  print(3)
else:
  print(2)
  
if c==mx:
  print(1)
elif c==mn:
  print(3)
else:
  print(2)