a=input()
b=input()
la=len(a)
lb=len(b)
ans="UNRESTORABLE"
for i in range(la-lb+1):
  k=1
  for j in range(lb):
    if a[i+j]=="?":
      continue
    if a[i+j]!=b[j]:
      k=0
  if k==1:
    ans=i
if ans=="UNRESTORABLE":
  print(ans)
else:
  ans=a[:ans]+b+a[ans+lb:]
  print(ans.replace("?","a"))