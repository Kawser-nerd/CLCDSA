n=int(input())
b=200
s=0
for i in range(n):
  a=int(input())
  s+=a
  if a%10!=0:
    b=min(b,a)
if s%10!=0:
  print(s)
elif b<200:
  print(s-b)
else:
  print(0)