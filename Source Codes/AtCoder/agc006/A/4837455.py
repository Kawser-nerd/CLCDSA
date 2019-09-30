n=int(input())
a=input()
b=input()
c=0
for i in range(1,n):
  if a[-1*i:]==b[:i]:
    c=i
if a==b:
  c=n
print(2*n-c)