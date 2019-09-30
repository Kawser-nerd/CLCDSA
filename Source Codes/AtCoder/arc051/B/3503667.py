k=int(input())
a,b,c,d=2,0,0,0
for _ in range(k):
  d=a
  c=2*a if b==0 else a+b
  a,b=c,d
print(a,b)