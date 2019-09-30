a=int(input())
list=list(map(int,input().split()))
flag=False
ans=30
for i in range(31):
  for j in list:
    if j % (2**i) != 0:
      if not(flag):
        flag = True
        ans = i-1
print(ans)