a,b,k=map(int,input().split())
s=set()
if k>(b-a):
  for i in range(a,b+1):
    print(i)
else:
  for i in range(min(k,b-a)):
    s.add(a+i)
    s.add(b-i)
  arr=list(s)
  arr=sorted(arr)
  for i in arr:
    print(i)