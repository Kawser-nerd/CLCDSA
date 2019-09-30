a=list(map(int,input().split()))
a.sort()
a.reverse()
ans=[]
for i in range(3):
  for j in range(i+1,4):
    for k in range(j+1,5):
      ans.append(a[i]+a[j]+a[k])
ans.sort()
print(ans[-3])