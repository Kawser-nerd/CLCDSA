n=int(input())
li=[]
for i in range(n):
  li.append(int(input()))
li=sorted(li)
for i in range(n-1):
  if li[i]==li[i+1]:
    n=n-1
  else:
    pass
print(n)