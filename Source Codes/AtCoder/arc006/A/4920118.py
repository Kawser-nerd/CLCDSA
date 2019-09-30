el=list(map(int,input().split()))
b=int(input())
ll=list(map(int,input().split()))
c=0
nom=-1
for i in ll:
  if el.count(i)>0:
    c+=1
  else:
    nom=i
if c==5:
  if nom==b:
    print(2)
    exit()
  else:
    print(3)
    exit()
elif c==6:
  print(1)
  exit()
elif c==4:
  print(4)
  exit()
elif c==3:
  print(5)
  exit()
else:
  print(0)