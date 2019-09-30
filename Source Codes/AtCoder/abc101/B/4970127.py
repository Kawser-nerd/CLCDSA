def S(num):
  ret=0
  for i in range(10):
    ret+=int((num%(10**(i+1)))/(10**i))
  return ret

n=int(input())
a=S(n)
if n%a == 0:
  print('Yes')
else:
  print('No')