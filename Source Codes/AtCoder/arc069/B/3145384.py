n=int(input())
s=input()

patterns=[("S","W"),("W","S"),("S","S"),("W","W")]

def solve(pattern):
  l=[True]*n
  l[0],l[1]=pattern
  for i in range(1,n-1):
    if (s[i]=="o" and l[i]=="S") or (s[i]=="x" and l[i]=="W"):
      l[i+1]=l[i-1]
    else:
      if l[i-1]=="S":
        l[i+1]="W"
      else:
        l[i+1]="S"
  if (s[-1]=="o" and l[-1]=="S") or (s[-1]=="x" and l[-1]=="W"):
    va=(l[-2]==l[0])
  else:
    va=(l[-2]!=l[0])
  if (s[0]=="o" and l[0]=="S") or (s[0]=="x" and l[0]=="W"):
    vb=(l[1]==l[-1])
  else:
    vb=(l[1]!=l[-1])
  return va&vb,l

for pattern in patterns:
  res,string=solve(pattern)
  if res:
    print(*string,sep="")
    break
else:
  print(-1)