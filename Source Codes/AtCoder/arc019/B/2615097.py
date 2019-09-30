n=input()
if len(n)==1:
  print(0)
  exit()

r=n[::-1]

t=0
for i in range(len(n)//2):
  if n[i]!=r[i]:
    t+=1
if t==0 :
  print(25 * 2*(len(n)//2))
elif t==1:
  print(24 * 2 + 25*(len(n)-2))
else:
  print(25 * len(n))