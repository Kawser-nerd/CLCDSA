def q():
  print(0)
  exit()
n,d = map(int,input().split())
x,y = map(int,input().split())
if x%d + y%d > 0:
  q()
else:
  x,y = abs(x//d),abs(y//d)
  if x<y:
    x,y = y,x
if (n+x+y)%2 > 0:
  q()
a,b = (n-x-y)//2,(n-x+y)//2
if a<0 or b<0:
  q()
p = 1
c = 2*n
for i in list(range(a))+list(range(b)):
  p = p*(n-i)/(i+1)
  while p>1:
    p /= 2
    c -= 1
for i in range(c):
  p /= 2
print(p)