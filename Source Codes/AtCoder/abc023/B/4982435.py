n=int(input())
s=input()
a=n//2
ans=1
if n%2<1:
  ans=0
else:
  for i in range(a+1):
    if i%3==0:
      if s[a-i]!="b" or s[a+i]!="b":
        ans=0
    elif i%3==1:
      if s[a-i]!="a" or s[a+i]!="c":
        ans=0
    else:
      if s[a-i]!="c" or s[a+i]!="a":
        ans=0
if ans:
  print(n//2)
else:
  print(-1)