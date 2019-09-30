n=int(input())
hoge=list(map(int,input().split()))
m=int(input())
huga=list(map(int,input().split()))

for i in range(m):
  hoge.append(huga[i])
  
hoge2=list(set(hoge))

if(len(hoge)==len(hoge2)):
  print("YES")
else:
  print("NO")