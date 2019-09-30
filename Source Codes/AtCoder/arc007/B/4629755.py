n,m=map(int,input().split())
outside=0
inside=[i+1 for i in range(n)]
for i in range(m):
  x=int(input())
  if x in inside:
    l=outside
    outside=inside[inside.index(x)]
    inside[inside.index(x)]=l
for i in range(n):print(inside[i])