import collections as c,math
f=math.factorial
s=input()
n=len(s)
a=n*-~n//2+1
for i in c.Counter(s).values():
  a-=i
  if i>1:
    a-=f(i)//f(i-2)//2
print(a)