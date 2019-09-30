s=input()
alphabet="abcdefghijklmnopqrstuvwxyz"
list=[s.count(x) for x in alphabet]
for i in range(len(list)):
  if list[i]%2==0:
    list[i]=0
  else:
    list[i]=1
print("Yes" if sum(list)==0 else "No")