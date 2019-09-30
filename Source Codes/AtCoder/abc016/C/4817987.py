n,m=map(int,input().split())
l1=[set()for i in range(n)]
l2=[{i}for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  a,b=a-1,b-1
  l1[a].add(b)
  l1[b].add(a)
for i in range(n):
  for j in l1[i]:
    l2[i]=l2[i].union(l1[j])
for i in range(n):
  print(len(l2[i].difference(l1[i]))-1)