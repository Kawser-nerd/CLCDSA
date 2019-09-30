i=int(input())
a=int(input())
b=int(input())
c=int(input())
s=0
boo=True
if i==a or i==b or i==c:
  print("NO")
else:
  while i>0 and boo==True:
    if i-3==a or i-3==b or i-3==c:
      if i-2==a or i-2==b or i-2==c:
        if i-1==a or i-1==b or i-1==c:
          boo=False
          print("NO")
        else:
          i-=1
      else:
        i-=2
    else:
      i-=3
    s+=1
  if s<=100 and boo:
    print("YES")
  elif s>100 and boo:
    print("NO")