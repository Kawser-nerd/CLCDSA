def p(a,b):
  count=0
  for i in range(a,b+1):
    si=str(i)
    if si[0]==si[-1] and si[1]==si[-2]:
      count+=1
  return count

n,m=map(int,input().split())
print(p(n,m))