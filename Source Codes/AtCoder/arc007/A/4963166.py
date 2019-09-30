x=input()
s=list(input())
l=[]
for i in s:
  if i!=x:
    l.append(i)
print(''.join(l))