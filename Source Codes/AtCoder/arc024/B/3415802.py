n=int(input())
a=[int(input()) for i in range(n)]
if len(set(a))==1:
  print(-1)
  exit()
a+=a
m=0
c=0
i0=2
for i in a:
  c = 1 if i0!=i else c+1
  m=max(m,c)
  i0=i
print((m-1)//2 +1)