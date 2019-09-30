h,w=map(int,input().split())
a,b=0,0
ans="Possible"
for y in range(h):
  m=input()
  a=m.find("#")
  if a<b:
    ans="Impossible"
    break
  b=m.rfind("#")
print(ans)