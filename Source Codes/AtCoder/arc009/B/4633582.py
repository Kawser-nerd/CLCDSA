z,n,a,b=input().split(),int(input()),[],[]
for i in range(n):
  m=input()
  x=0
  for j in range(len(m)):x+=(z.index(m[len(m)-j-1]))*(10**j)
  a.append(x)
  b.append(m)
def swap(ab,ba,X):
  abc=X[ab]
  X[ab]=X[ba]
  X[ba]=abc
h=n
while 1:
  hh=a[:]
  if h>1:h=round(h//1.3)
  for i in range(n-h):
    if a[i]>a[i+h]:
      swap(i,i+h,a)
      swap(i,i+h,b)
  if hh==a and h==1:break
for i in b:print(i)