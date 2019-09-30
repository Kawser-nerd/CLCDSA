def f(b,n):
  if n<b:return n
  return f(b,n//b)+n%b

n=int(input())
s=int(input())

if n==s:
  print(n+1)
  exit()
for b in range(2,int(n**0.5)+1):
  if f(b,n)==s:
    print(b)
    break
else:
  for p in range(1,int(n**0.5)+1)[::-1]:
    b,m=divmod(n-s+p,p)
    if m==0 and b>=2 and f(b,n)==s:
      print(b)
      break
  else:
    print(-1)