def gcd(a, b):
    if b == 0:return a
    return gcd(b, a % b)
  
n=int(input())
for i in range(n):
  ans="Yes"
  a,b,c,d=map(int,input().split())
  if a<b or d<b:
    ans="No"
  elif b<=c:
    ans="Yes"
  else:
    if c<b-gcd(b,d)+a%gcd(b,d):
      ans="No"
  print(ans)