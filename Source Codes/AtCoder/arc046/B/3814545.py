n=int(input())
a,b=map(int,input().split())
ans=1
if n<=a:
  ans=0
elif (a==b and n%(a+1)!=0) or a>b:
  ans=0
print(["Takahashi","Aoki"][ans])