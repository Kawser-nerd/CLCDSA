h,w=map(int,input().split())
b=[list(input()) for _ in range(h)]
for i in range(h-1,-1,-1):
  if b[i].count('.')==w:
    del b[i]
    h-=1
for i in range(w-1,-1,-1):
  count=0
  for j in range(h):
    if b[j][i]=='.':
      count+=1
  if count==h:
    for j in range(h):
      tmp=b[j][:i]+b[j][i+1:]
      b[j]=tmp
for i in range(h):
  print(''.join(b[i]))