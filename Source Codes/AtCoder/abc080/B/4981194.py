def n(num):
  ret=0
  for i in range(10):
    ret+=int((num%(10**(i+1)))/(10**i))
  return ret

a=int(input())
if a%n(a)==0:
  print('Yes')
else:
  print('No')