hoge=list(input())
n=int(input())
kari=""
for i in range(n):
  a,b=map(int,input().split())
  huga=hoge[a-1:b]
  huga=huga[::-1]
  hoge[a-1:b]=huga
  
for i in range(len(hoge)):
  print(hoge[i],end="")
print("")