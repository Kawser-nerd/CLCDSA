n=int(input())
li=[n]
x=0
i=0
while i<=1000000 and x==0:
  if li[i]%2==0:
    li.append(li[i]/2)
    for j in range(i):
      if li[i+1]==li[j]:
        x=i+2
      else:pass
    i+=1
  else:
    li.append(3*li[i]+1)
    for j in range(i):
      if li[i+1]==li[j]:
        x=i+2
      else:pass
    i+=1
print(x)