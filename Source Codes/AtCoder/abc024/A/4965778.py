a,b,c,d=map(int,input().split())
n,m=map(int,input().split())
sum=a*n+b*m
if (n+m)>=d:
  sum-=(n+m)*c
print(sum)