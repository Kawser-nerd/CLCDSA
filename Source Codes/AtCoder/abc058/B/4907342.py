o=input()
e=input()
ans=''
for i in range(min(len(o),len(e))):
  ans+=o[i]
  ans+=e[i]
if len(o)>len(e):
  ans+=o[-1]
print(ans)