T=[0]
t=2
A=[]
a=1
for i in range(60):
  T.append(t)
  A.append(a)
  t*=2
  t+=1
  t*=2
  a*=2
  a+=1
  a*=2
n=int(input())
if len(bin(n))%2==0:
  if T[(len(bin(n))-2)//2]>n:
    print('Aoki')
  else:
    print('Takahashi')
else:
  if A[(len(bin(n))-2)//2]>n:
    print('Takahashi')
  else:
    print('Aoki')