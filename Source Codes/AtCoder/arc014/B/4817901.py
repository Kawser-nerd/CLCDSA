N=int(input())
l=[]
a=input()
l.append(a)
b=''
f=1
shori=-1
for i in range(N-1):
  b=input()
  if f==0:
    if a[-1]!=b[0] or l.count(b)>0:
      if shori==-1:
        shori=0
    f=1
  else:
    if a[-1]!=b[0] or l.count(b)>0:
      if shori==-1:
        shori=1
    f=0
  a=b
  l.append(b)
if shori==0:
  print('LOSE')
elif shori==1:
  print('WIN')
else:
  print('DRAW')