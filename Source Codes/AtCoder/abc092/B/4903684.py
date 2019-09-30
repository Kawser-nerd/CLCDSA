n=int(input())
a,b=map(int,input().split())
c=0
for i in range(n):
  d=int(input())
  e=0
  while d*e+1<=a:
    c+=1
    e+=1
print(c+b)