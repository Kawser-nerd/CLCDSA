N = input()
s = 0
for i in N:
  s+=int(i)
if(int(N)%s == 0):
  print('Yes')
else:
  print('No')