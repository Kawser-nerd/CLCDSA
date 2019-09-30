n=int(input())
if n==1:
  print(0)
elif n==2:
  print(0)
elif n==3:
  print(1)
else:
  a2=0
  a1=0
  a0=1
  for i in range(3,n):
    a=(a2+a1+a0)%10007
    a2=a1
    a1=a0
    a0=a
  print(a)