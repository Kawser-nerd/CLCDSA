a=input()
flag = 0
for i in range(len(a)-1):
  if flag == 0:
    if a[i]==a[i+1]:
      print("{0} {1}".format(i+1,i+2))
      flag = 1
    elif i+2!=len(a) and a[i]==a[i+2]:
      print("{0} {1}".format(i+1,i+3))
      flag = 1
if flag == 0:
  print("-1 -1")