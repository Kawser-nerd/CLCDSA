n=input()
m=n[0]
for i in range(len(n)-1):
  m+=n[0]
if int(n)>int(m):
  if n[0]!=str(9):
    a=str(int(n[0])+1)
    for j in range(len(n)-1):
      a+=str(int(n[0])+1)
    print(a)
  else:
    b=str(1)
    for k in range(len(n)):
      b+=str(1)
    print(b)
else:
  print(m)