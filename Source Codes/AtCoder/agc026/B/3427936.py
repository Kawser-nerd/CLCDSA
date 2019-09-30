import fractions
n = int(input())
for i in range(n):
  a,b,c,d = map(int,input().split())
  if b > d or b > a:print("No")
  elif b <= c:print("Yes")
  else:
    num = fractions.gcd(b,d)
    if b-num+(a%num) > c:print("No")
    else:print("Yes")