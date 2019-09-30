n=int(input())
m=[]
for i in range(3):
  m.append(int(input()))
ret="YES"
if n in m:
  ret="NO"
else:
  m.sort()
  if n==300:
    if [i for i in m if i%3==0]:
      ret="NO"
  else:
    tmp=(m[2]-m[1])*(m[1]-m[0])
    if m[2]<n and tmp==1:
      ret="NO"
    elif n==299:
      if tmp==4:
        ret="NO"
      elif max(m[2]%3,m[1]%3)==2 and m[1]%3*m[0]%3==0:
        ret="NO"
      elif m[2]%3==0 and m[2]-m[1]==1:
        ret="NO"
      elif m[1]%3==0 and m[1]-m[0]==1:
        ret="NO"
    elif n==298:
      if m[0]-m[1]==1 and m[0]%3==0:
        ret="NO"
      elif m[2]%3==1 and tmp==4:
        ret="NO"
      elif m[2]%3==1 and m[1]%3==0 and m[1]-m[0]==1:
        ret="NO"
print(ret)