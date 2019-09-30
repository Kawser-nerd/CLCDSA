a=[int(input())for _ in[0]*int(input())]*2
if len(set(a))<2:
  print(-1)
  exit()
b=c=m=0
for i in a:
  if i:
    b+=1
    m=max(m,b,c)
    c=0
  else:
    c+=1
    m=max(m,b,c)
    b=0
print(~-m//2+1)