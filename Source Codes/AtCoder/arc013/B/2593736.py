n=int(input())
h1=0
h2=0
h3=0
for i in range(n):
  a,b,c=sorted([int(i) for i in input().split()])
  h1=max(h1,a)
  h2=max(h2,b)
  h3=max(h3,c)
print(h1*h2*h3)