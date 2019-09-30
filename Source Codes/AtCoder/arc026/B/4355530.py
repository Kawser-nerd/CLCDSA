def d(n):
  if n<2:return 0
  l=[1]
  for i in range(2,int(n**.5)+1):
    if n%i<1:
      l.extend([i,n//i])
  if len(l)>1and l[-1]==l[-2]:
    return sum(l[:-1])
  return sum(l)
n=int(input())
a=d(n)
if n==a:
  print('Perfect')
elif n>a:
  print('Deficient')
else:
  print('Abundant')