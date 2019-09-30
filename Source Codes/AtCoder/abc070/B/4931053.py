a,b,c,d=map(int,input().split())
if a<=c<=b:
  if b<d:
    print(b-c)
  else:
    print(d-c)
elif c<=a<=d:
  if b<d:
    print(b-a)
  else:
    print(d-a)
else:
  print(0)