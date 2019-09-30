n,m=map(int,input().split())
x,y=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
def binarysearch(x,line):
  ng=-1
  ok=len(line)
  while abs(ok-ng)>1:
    mid=(ok+ng)//2
    if line[mid]>=x:
      ok=mid
    else:
      ng=mid
  return ok
ans=0
time=0
flag=True
while 1:
  if flag:
    xyz=binarysearch(time,a)
    if xyz==len(a):
      break
    time=a[xyz]+x
    flag=False
  else:
    xyz=binarysearch(time,b)
    if xyz==len(b):
      break
    time=b[xyz]+y
    ans+=1
    flag=True
print(ans)