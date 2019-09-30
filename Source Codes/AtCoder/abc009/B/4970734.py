n=int(input())
s=set()
for i in range(n):
  i=int(input())
  s.add(i)
l=list(s)
l.sort(reverse=1)
print(l[1])