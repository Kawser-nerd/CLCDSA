t=int(input())
def gcd(x,y):
  if y==0:
    return x
  else:
    return gcd(y,x%y)
for i in range(t):
  a,b,c,d=map(int,input().split())
  if a<b:
    print("No")
  elif b>d:
    print("No")
  elif c>b:
    print("Yes")
  else:
    if b-gcd(b,d)+a%gcd(b,d)>c:
      print("No")
    else:
      print("Yes")