a=list(input())
b=list(input())
c=list(input())
x=a[0]
for i in range(len(a)+len(b)+len(c)):
  if x=="a":
    if len(a)==0:
      print("A")
      break
    else:
      x=a.pop(0)
  elif x=="b":
    if len(b)==0:
      print("B")
      break
    else:
      x=b.pop(0)
  else:
    if len(c)==0:
      print("C")
      break
    else:
      x=c.pop(0)