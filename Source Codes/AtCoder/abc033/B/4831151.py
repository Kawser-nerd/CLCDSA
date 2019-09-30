n=int(input())
people=0
max_a="hoge"
max_b=0
for i in range(n):
  a,b=map(str,input().split())
  people+=int(b)
  if(max_b<int(b)):
    max_b=int(b)
    max_a=a

if(people<2*max_b):
  print(max_a)
else:
  print("atcoder")