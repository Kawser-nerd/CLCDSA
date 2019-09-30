q = int(input())
for i in range(q):
  a, b = list(map(int, input().split()))
  if a==b:
    ans = 2*a-2
  elif abs(a-b)==1:
    ans = 2*min(a, b)-2
  else:
    c = (a*b)**0.5
    if c%1==0:
      c = int(c)-1
    else:
      c = int(c)
    if c*(c+1)>=a*b:
      ans = 2*c-2
    else:
      ans = 2*c-1
  print(ans)