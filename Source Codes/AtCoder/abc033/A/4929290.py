N = input()
x = N[0]
flag = True
for i in N:
  if(i!=x):
    flag = False
  x=i
if(flag):
  print('SAME')
else:
  print('DIFFERENT')