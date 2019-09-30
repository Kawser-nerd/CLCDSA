n=int(input())
arr=[]
flag=True
s=input()
arr.append(s)
for _ in range(n-1):
  w=input()
  if w in arr:
    flag=False
  if s[-1] != w[0]:
    flag=False
  arr.append(w)
  s=w
if flag:
  print('Yes')
else:
  print('No')