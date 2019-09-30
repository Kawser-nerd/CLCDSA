s=input()
a=sorted(set(s))
E="abcdefghijklmnopqrstuvwxyz"
if len(set(a))==26:
  print("None")
else:
  count=0
  for i in range(len(a)):
    if a[i]==E[i]:
      count+=1
    else:
      break
  print(E[count])