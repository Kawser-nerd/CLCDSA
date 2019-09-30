a,b=map(int,input().split())
n=int(input())
for i in range(n):
  hoge=int(input())
  if(hoge<a):
    print(a-hoge)
  elif(b<hoge):
    print(-1)
  else:
    print(0)