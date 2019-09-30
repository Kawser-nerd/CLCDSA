hoge=input()
ans=0
for i in range(len(hoge)):
  ans+=hoge.count(hoge[i])%2
if(ans==0):
  print("Yes")
else:
  print("No")